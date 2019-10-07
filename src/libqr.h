#ifndef _LIBQR_
#define _LIBQR_

#include <node.h>
#include <node_object_wrap.h>
#include "./qrencode.h"

namespace _libqr
{
using node::ObjectWrap;
using v8::Function;
using v8::FunctionCallback;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Persistent;
using v8::Value;

class LibQr : public ObjectWrap
{
public:
    static void Init(Local<Object> exports);

private:
    static Persistent<Function> constructor;
    static void New(const FunctionCallbackInfo<Value> &args);
    // 生成二维码
    static void GetQrCode(const FunctionCallbackInfo<Value> &args);
    // 写入文件
    static void WriteFile(std::string path, QRcode *qrc);
    explicit LibQr();
    ~LibQr();
};
} // namespace _libqr

#endif