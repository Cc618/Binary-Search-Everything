#!/usr/bin/env python3

# Will replace special variables such as $SUMMARY$ with their contents

with open("public/index.html") as f:
    index = f.read()

with open("public/summary.html") as f:
    summary = f.read()

index = index.replace("$SUMMARY$", summary)

with open("public/index.html", "w") as f:
    f.write(index)
