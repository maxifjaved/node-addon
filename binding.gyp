{
  "targets": [
    {
      "target_name": "handler",
      "sources": [ "addon/index.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}