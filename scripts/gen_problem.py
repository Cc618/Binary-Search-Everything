#!/usr/bin/env python3

# Generates a problem page from its name

import os
import sys
import subprocess as sp
import html


def markdown_to_html(path):
    proc = sp.run(
        ["kramdown", "--config-file", "scripts/kramdown_config.yml", path],
        capture_output=True,
    )

    assert proc.returncode == 0, f"Failed to convert {path}"

    return str(proc.stdout, "utf8")


def highlight_code(code):
    txt = '<div class="language-cpp highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="c1">'
    txt = txt + html.escape(code)
    txt = txt + "</span></code></pre></div>"

    return txt


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"usage: {sys.argv[0]} <problem-name>", file=sys.stderr)
        exit(1)

    # TODO : Beautify name
    name = sys.argv[1]
    name_beautiful = name[name.index("_") + 1 :].replace("_", " ")

    # TODO : Solution

    with open("web/template.html") as f:
        template = f.read()

    exo = f"exercises/{name}.md"
    solution = f"solutions/{name}.md"
    code = f"solutions/{name}.cpp"

    assert os.path.exists(exo), f"{exo} not found"
    assert os.path.exists(solution), f"{solution} not found"
    assert os.path.exists(code), f"{code} not found"

    content_exo = markdown_to_html(exo)
    content_solution = markdown_to_html(solution)
    with open(code) as f:
        content_code = f.read()
    code_begin = content_code.index("$BEGIN$") + len("$BEGIN$") + 1
    code_end = content_code.index("// $END$")
    content_code = content_code[code_begin:code_end]
    content_code = highlight_code(content_code)

    template = template.replace("$FULL_NAME$", name)
    template = template.replace("$NAME$", name_beautiful)
    template = template.replace("$EXERCISE$", content_exo)
    template = template.replace("$SOLUTION$", content_solution)
    template = template.replace("$CODE$", content_code)

    # Save content
    with open(f"public/{name}.html", "w") as f:
        f.write(template)

    # Update summary
    with open(f"public/summary.html", "a") as f:
        print(
            f'<li class="camel"><a href="{name}.html">{name_beautiful}</a></li>', file=f
        )
