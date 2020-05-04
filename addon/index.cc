#include <nan.h>
using namespace v8;

void Method(const Nan::FunctionCallbackInfo<Value> &info)
{
 info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}

void Init(Local<Object> exports)
{
 Local<Context> context = exports->CreationContext();
 exports->Set(context,
              Nan::New("hello").ToLocalChecked(),
              Nan::New<FunctionTemplate>(Method)
                  ->GetFunction(context)
                  .ToLocalChecked());
}

NODE_MODULE(hello, Init)