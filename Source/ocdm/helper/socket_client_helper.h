/*
 * Copyright (c) 2018, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __SOCKET_CLIENT_HELPER_H__
#define __SOCKET_CLIENT_HELPER_H__

#include <unistd.h>

#define SOCKET_INVALID_FD (-1)
#define SOCKET_SEND_TIMEOUT (1) // second(s)

namespace media {

class SocketClient
{
public:
  // Constructor.
  SocketClient(void) {
    m_SocketFd = SOCKET_INVALID_FD;
  }

  // Destructor.
  ~SocketClient(void) {
    Disconnect();
  }

  int Connect(int f_SocketChannelId);
  
  void Disconnect(void) {
    if(m_SocketFd >= 0) {
      close(m_SocketFd);
      m_SocketFd = SOCKET_INVALID_FD;
    }
  }
	
  int SendFileDescriptor(int f_SecureFd, uint32_t f_Size);

private:
  int m_SocketFd;
};

}  // namespace media

#endif  // #ifdef __SOCKET_CLIENT_HELPER_H__
