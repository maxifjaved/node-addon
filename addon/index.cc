//Simple Hello Addon
#include <nan.h>

void Handler(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
 info.GetReturnValue().Set(Nan::New("Word").ToLocalChecked());
}
void Init(v8::Local<v8::Object> exports)
{
 v8::Local<v8::Context> context = exports->CreationContext();
 exports->Set(context,
              Nan::New("hello").ToLocalChecked(),
              Nan::New<v8::FunctionTemplate>(Handler)->GetFunction(context).ToLocalChecked());
}
NODE_MODULE(addon, Init)