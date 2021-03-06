// Copyright 2012 Google Inc. All Rights Reserved.
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
//
//
// The header contains one inline function, SupersonicInit(),
// which initialises atomicops for x86 architecture and the Google logging
// module.
#ifndef SUPERSONIC_OPENSOURCE_AUXILIARY_INIT_H_
#define SUPERSONIC_OPENSOURCE_AUXILIARY_INIT_H_

#if defined(__GNUC__) && (defined(__i386) || defined(__x86_64__))
#include "supersonic/utils/atomicops-internals-x86.h"
const bool archX86 = true;
#else
const bool archX86 = false;
#endif

#include <glog/logging.h>
#include "supersonic/utils/logging-inl.h"

namespace supersonic {

inline void SupersonicInit(const char* argv0) {
  google::InitGoogleLogging(argv0);
  if (archX86) {
    AtomicOps_x86CPUFeaturesInit();
  }
}
}  // namespace supersonic
#endif  // SUPERSONIC_OPENSOURCE_AUXILIARY_INIT_H_
