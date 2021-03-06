#ifndef __MODULE_WEBSOCKET_H
#define __MODULE_WEBSOCKET_H

#ifndef MODULE_NAME
#define MODULE_NAME WebSocket
#endif

#include "../core/core.h"
#include "../cryptalgo/cryptalgo.h"

#ifdef __WIN32__
#include "./windows/include/zlib.h"
#else
#include "zlib.h"
#endif

#ifdef __WIN32__
#undef EXTERNAL
#ifdef WEBSOCKET_EXPORTS
#define EXTERNAL EXTERNAL_EXPORT
#else
#define EXTERNAL EXTERNAL_IMPORT
#endif
#else
#define EXTERNAL
#endif

#endif // __MODULE_WEBSOCKET_H
