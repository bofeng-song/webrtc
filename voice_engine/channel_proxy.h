/*
 *  Copyright (c) 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_VOICE_ENGINE_CHANNEL_PROXY_H_
#define WEBRTC_VOICE_ENGINE_CHANNEL_PROXY_H_

#include "webrtc/voice_engine/channel_manager.h"

#include <string>

namespace webrtc {
namespace voe {

// This class provides the "view" of a voe::Channel that we need to implement
// webrtc::AudioSendStream and webrtc::AudioReceiveStream. It serves two
// purposes:
//  1. Allow mocking just the interfaces used, instead of the entire
//     voe::Channel class.
//  2. Provide a refined interface for the stream classes, including assumptions
//     on return values and input adaptation.
class ChannelProxy {
 public:
  ChannelProxy();
  explicit ChannelProxy(const ChannelOwner& channel_owner);
  virtual ~ChannelProxy() {}

  virtual void SetRTCPStatus(bool enable);
  virtual void SetLocalSSRC(uint32_t ssrc);
  virtual void SetRTCP_CNAME(const std::string& c_name);

 private:
  ChannelOwner channel_owner_;
};
}  // namespace voe
}  // namespace webrtc

#endif  // WEBRTC_VOICE_ENGINE_CHANNEL_PROXY_H_
