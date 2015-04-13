/*
 * Copyright 2015 Aldebaran
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <alvalue/alvalue.h>

#include <ros/serialization.h>
#include <std_msgs/String.h>

#include "info.hpp"

namespace alros
{
namespace publisher
{

InfoPublisher::InfoPublisher( const std::string& topic )
  : BasePublisher( topic )
{
}

void InfoPublisher::publish( const std_msgs::String& info_msg )
{
  pub_.publish( info_msg );
}

void InfoPublisher::reset( ros::NodeHandle& nh )
{
  // We latch as we only publish once
  pub_ = nh.advertise<std_msgs::String>( topic_, 1, true );

  is_initialized_ = true;
}

} // publisher
} //alros
