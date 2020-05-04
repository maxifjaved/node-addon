{
  "targets": [
    {
      "target_name": "hello",
      "sources": [ "addon/index.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}