//Addon With Callback

#include <nan.h>

using v8::Function;
using v8::Local;
using v8::Object;
using v8::Value;

void RunCallback(const Nan::FunctionCallbackInfo<Value> &info)
{
 Local<Function> callback = info[0].As<Function>();

 const unsigned argc = 1;
 Local<Value> argv[argc] = {Nan::New("Random Text").ToLocalChecked()};

 Nan::AsyncResource resource("nan:makeCallback");
 resource.runInAsyncScope(Nan::GetCurrentContext()->Global(), callback, argc, argv);
}
void Init(Local<Object> exports, Local<Object> module)
{
 Nan::SetMethod(module, "exports", RunCallback);
}

NODE_MODULE(addon, Init)