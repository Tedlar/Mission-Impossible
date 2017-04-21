/*
 * QueueData.h
 *
 *  Created on: 05.02.2017
 *      Author: tedlar
 */

#ifndef LOGIC_KEYBOARD_QUEUEDATA_H_
#define LOGIC_KEYBOARD_QUEUEDATA_H_

#include <boost/circular_buffer.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/bind.hpp>
#include <QDebug>

//!  QueueData class
/*!

*/
template<class T>
class QueueData {
public:
	typedef boost::circular_buffer<T> container_type;
	typedef typename container_type::size_type size_type;
	typedef typename container_type::value_type value_type;
	typedef typename boost::call_traits<value_type>::param_type param_type;

	//! constructor
	/*!
	*/
	QueueData(const QueueData&) = delete;
	QueueData& operator = (const QueueData&) = delete;
	QueueData(size_type size = 3) : unread_(0), container_(size) {}

	//! write to queue
	/*!
	*/
	void write(const param_type& item) {
	    boost::mutex::scoped_lock lock(mutex_);
	    container_.push_back(const_cast<param_type&>(item));
	    if ( unread_ < container_.capacity() )
	    	++unread_;
	    lock.unlock();
	    notEmpty_.notify_one();
	}

	//! read from queue
	/*!
	*/
	void read(T& item) {
	    boost::mutex::scoped_lock lock(mutex_);
	    notEmpty_.wait(lock, boost::bind(&QueueData<value_type>::isNotEmpty, this));
	    std::swap(item, container_[0]);
	    container_.pop_front();
	    --unread_;
	}

private:
	size_type unread_;
	container_type container_;
	boost::mutex mutex_;
	boost::condition notEmpty_;

private:
	bool isNotEmpty() const { return unread_ > 0; }
};


#endif // LOGIC_KEYBOARD_QUEUEDATA_H_
