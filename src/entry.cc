#include "libqr.h"
#include <node.h>

namespace _libqr {
    void InitAll(Local<Object> exports) {
        LibQr::Init(exports);
    }

    NODE_MODULE(addon, InitAll);
}