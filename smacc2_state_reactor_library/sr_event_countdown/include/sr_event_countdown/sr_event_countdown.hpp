// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <boost/statechart/event.hpp>
#include <map>
#include <smacc2/common.hpp>
#include <smacc2/smacc_state_reactor.hpp>
#include <typeinfo>

namespace smacc2
{
namespace state_reactors
{
template <typename TSource, typename TObjectTag = EmptyObjectTag>
struct EvCountdownEnd : sc::event<EvCountdownEnd<TSource, TObjectTag>>
{
};

//-----------------------------------------------------------------------
class SrEventCountdown : public StateReactor
{
private:
  std::map<const std::type_info *, bool> triggeredEvents;
  int eventCount_;

public:
  SrEventCountdown(int eventCount);

  virtual void onInitialized() override;

  virtual void onEventNotified(const std::type_info * eventType) override;

  virtual bool triggers() override;
};
}  // namespace state_reactors
}  // namespace smacc2
