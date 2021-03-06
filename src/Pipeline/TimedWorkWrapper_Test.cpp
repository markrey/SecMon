/*
 * TimedWorkWrapper_Test.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: Richard
 *
 *  Copyright 2017 Richard Stilborn
 *  Licensed under the MIT License
 */

#include "TimedWorkWrapper.h"
#include <gtest/gtest.h>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>

void ttw_test_function(const int i) {
  if (i < 0)
    return;
}

TEST(TimedWorkWrapperConstruct, Success) {
  boost::asio::io_service io_service;
  std::shared_ptr<pipeline::TimeStatsQueue> tsq(new pipeline::TimeStatsQueue());
  try {
    pipeline::TimedWorkWrapper<const int> tww(io_service, boost::bind(ttw_test_function, 1), 11, tsq);
  } catch (const char* msg) {
    FAIL() << msg;
  }
}

