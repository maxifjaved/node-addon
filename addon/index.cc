//Addon With Callback

#include <nan.h>

using v8::Context;
using v8::Function;
using v8::FunctionTemplate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::Value;

void Handler(const Nan::FunctionCallbackInfo<Value> &info)
{
 Local<Context> context = info.GetIsolate()->GetCurrentContext();
 if (info.Length() < 3)
 {
  Nan::ThrowTypeError("Missing arguments");
  return;
 }
 if (!info[0]->IsNumber() || !info[1]->IsNumber() || !info[2]->IsFunction())
 {
  Nan::ThrowTypeError("Invalid arguments");
  return;
 }

 double arg0 = info[0]->NumberValue(context).FromJust();
 double arg1 = info[1]->NumberValue(context).FromJust();
 Local<Function> callback = info[2].As<Function>();

 const unsigned argc = 1;
 Local<Value> argv[argc] = {Nan::New(arg0 + arg1)};

 Nan::AsyncResource resource("nan:makeCallback");
 resource.runInAsyncScope(Nan::GetCurrentContext()->Global(), callback, argc, argv);
}
void Init(Local<Object> exports, Local<Object> module)
{
 Local<Context> context = exports->CreationContext();
 exports->Set(context,
              Nan::New("handler").ToLocalChecked(),
              Nan::New<FunctionTemplate>(Handler)->GetFunction(context).ToLocalChecked());
 // Nan::SetMethod(module, "exports", RunCallback);
}

NODE_MODULE(addon, Init)