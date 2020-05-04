//Addon with function argument

#include <nan.h>
void Sum(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
 v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
 if (info.Length() < 2)
 {
  Nan::ThrowTypeError("Need two number for Sum");
  return;
 }

 if (!info[0]->IsNumber() || !info[1]->IsNumber())
 {
  Nan::ThrowTypeError("Not valid numbers");
  return;
 }

 double arg0 = info[0]->NumberValue(context).FromJust();
 double arg1 = info[1]->NumberValue(context).FromJust();

 v8::Local<v8::Number> result = Nan::New(arg0 + arg1);
 info.GetReturnValue().Set(result);
}
void Init(v8::Local<v8::Object> exports)
{
 v8::Local<v8::Context> context = exports->CreationContext();
 exports->Set(context,
              Nan::New("handler").ToLocalChecked(),
              Nan::New<v8::FunctionTemplate>(Sum)
                  ->GetFunction(context)
                  .ToLocalChecked());
}
NODE_MODULE(addon, Init)