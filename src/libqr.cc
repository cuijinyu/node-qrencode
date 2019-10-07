#include "./libqr.h"
#include "./qrenc.hpp"
#include <memory.h>

namespace _libqr
{

Persistent<Function> LibQr::constructor;

LibQr::LibQr() {}

LibQr::~LibQr() {}

void LibQr::New(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    if (args.IsConstructCall())
    {
        LibQr *qr = new LibQr();
        qr->Wrap(args.This());
        args.GetReturnValue().Set(args.This());
    }
    else
    {
        const int argc = 1;
        Local<Value> argv[argc] = {args[0]};
        Local<v8::Context> context = isolate->GetCurrentContext();
        Local<Function> cons = Local<Function>::New(isolate, constructor);
        Local<Object> result = cons->NewInstance(context, argc, argv).ToLocalChecked();
        args.GetReturnValue().Set(result);
    }
}

void LibQr::GetQrCode(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    Local<v8::String> content = args[0]->ToString();
    Local<v8::String> path = args[1]->ToString();
    v8::String::Utf8Value content_v8(content);
    v8::String::Utf8Value path_v8(path);
    QRcode *pQRC;
    FILE *f;
    pQRC = QRcode_encodeString(*content_v8, 0, QR_ECLEVEL_H, QR_MODE_8, 1);
    writeSVG(pQRC, *path_v8);
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "123"));
    QRcode_free(pQRC);
}

void LibQr::Init(Local<Object> exports)
{
    Isolate *isolate = exports->GetIsolate();

    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->SetClassName(v8::String::NewFromUtf8(isolate, "libqr"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    NODE_SET_PROTOTYPE_METHOD(tpl, "getQrCode", GetQrCode);
    constructor.Reset(isolate, tpl->GetFunction());
    exports->Set(v8::String::NewFromUtf8(isolate, "Libqr"), tpl->GetFunction());
}
} // namespace _libqr