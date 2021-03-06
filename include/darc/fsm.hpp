/*
 * Copyright (c) 2012, Prevas A/S
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Prevas A/S nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 *
 *
 * \author Morten Kjaergaard
 */

#pragma once

#include <boost/static_assert.hpp>
namespace darc
{

template<unsigned int State>
struct state
{
  const static unsigned int value = State;
};

template<unsigned int Event>
struct event_0
{
  const static unsigned int value = Event;
};

template<unsigned int Event,
         typename T1>
struct event_1 : event_0<Event>
{
  const T1& a1_;

  event_1(const T1& a1) :
    a1_(a1)
  {
  }
};

template<unsigned int Event,
         typename T1,
         typename T2>
struct event_2 : event_0<Event>
{
  const T1& a1_;
  const T2& a2_;

  event_2(const T1& a1, const T2& a2) :
    a1_(a1),
    a2_(a2)
  {
  }
};

template<typename Derived>
class fsm
{
protected:
  //** Internal stuff
  unsigned int state_;

  fsm() :
    state_(0)
  {
  }

public:
  template<typename Event>
  void post_event(Event event)
  {
    Derived* d_this = (Derived*)this;

    switch(state_)
    {
    case 0:
      d_this->handle(state<0>(), event);
      break;
    case 1:
      d_this->handle(state<1>(), event);
      break;
    case 2:
      d_this->handle(state<2>(), event);
      break;
    case 3:
      d_this->handle(state<3>(), event);
      break;
    case 4:
      d_this->handle(state<4>(), event);
      break;
    case 5:
      d_this->handle(state<5>(), event);
      break;
    default:
      assert(0);
      break;
    }
  }

  template<typename State>
  void trans(const State&)
  {
    state_ = State::value;
    BOOST_STATIC_ASSERT((State::value <= 5));
  }

};

}
