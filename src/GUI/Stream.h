/*
 * Stream.h
 *
 *  Created on: Aug 8, 2015
 *      Author: richard
 */

#ifndef GUI_STREAM_H_
#define GUI_STREAM_H_

#include <boost/core/noncopyable.hpp>
#include <boost/signals2/signal.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/thread/pthread/mutex.hpp>
#include <vector>

#include "Connection.h"
#include "StreamConnection.h"

class Stream : private boost::noncopyable {
public:
	Stream(boost::signals2::signal<void (boost::shared_ptr<std::vector<unsigned char>>)>& signal, int stream_id);
	virtual ~Stream();
	void registerNewConnection(http::connection_ptr conn);
	void deregisterConnection(http::stream_connection_ptr conn);
	boost::signals2::connection connectToSignal(const boost::signals2::signal<void (boost::shared_ptr<std::vector<unsigned char>>)>::slot_type &subscriber);
	int getStreamId() const;

private:
	std::vector<http::stream_connection_ptr> connection_list_;
	boost::mutex connection_list_mtx_;
	boost::signals2::signal<void (boost::shared_ptr<std::vector<unsigned char>>)>& signal_;
	int stream_id_;
};

#endif /* GUI_STREAM_H_ */