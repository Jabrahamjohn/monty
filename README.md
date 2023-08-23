<h1 align="center">
0x19. C - Stacks, Queues - LIFO, FIFO
</h1>

<p align="center">
   📄 🚀
</p>

<p align="center">
  <strong>
   Description
  </strong>
</p>

<p align="center">
 This knowledge of the data structures stacks and queues in C language, gives a base to build C
   programs that acts as a Monty bytecode interpreter.
</p>
<p>
this is a collaboration between the below listed persons asaad chadi and abraham john
</p>

# Copyright
Copyright (c) 2023 by:<br>[**Abraham John**](https://github.com/Jabrahamjohn)</br>[**Asaad Chadi**](https://github.com/asaadMXLV)

# Resources
<p><strong>Read or watch</strong>:</p>
<ul>
<li><a href="/rltoken/tn1X658KGumYYq_szFJI5w" title="Google" target="_blank">Google</a> </li>
<li><a href="/rltoken/0KVWTdE8xXy__jUfBfakCw" title="How do I use extern to share variables between source files in C?" target="_blank">How do I use extern to share variables between source files in C?</a></li>
<li><a href="/rltoken/udmomL4F4mF630D2Z-ltqg" title="Stacks and Queues in C" target="_blank">Stacks and Queues in C</a> </li>
<li><a href="/rltoken/fj_-SJXW-pWxgAnstsARoQ" title="Stack operations" target="_blank">Stack operations</a></li>
<li><a href="/rltoken/6Y_GVoIH_rV45xd7w0a9FA" title="Queue operations" target="_blank">Queue operations</a></li>
</ul>

### Compilation &amp; Output
<ul>
<li>Your code will be compiled this way:</li>
</ul>
<pre><code>$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
</code></pre>
<ul>
<li>Any output must be printed on <code>stdout</code></li>
<li>Any error message must be printed on <code>stderr</code>

<ul>
<li><a href="/rltoken/NUGvCZqs609VjEHeutkICw" title="Here is a link to a GitHub repository" target="_blank">Here is a link to a GitHub repository</a> that could help you making sure your errors are printed on <code>stderr</code></li>
</ul></li>
</ul>
<h1 align="center">The Monty language</h1>
<p>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python).<br>It relies on a unique stack, with specific instructions to manipulate it.<br> The goal of this project is to create an interpreter for Monty ByteCodes files.</p>
<p><strong>Monty byte code files</strong></p>
<p>Files containing Monty byte codes usually have the <code>.m</code> extension. Most of the industry uses this standard but it is not required by the specification of the language.<br>
There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>
<pre><code>AJ@Kali:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
AJ@Kali:~/monty$
</code></pre>
<p>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:</p>
<pre><code>Aj@Kali:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
AJ@kali:~/monty$
</code></pre>
<p><strong>The monty program</strong></p>
<ul>
<li>Usage: <code>monty file</code>

<ul>
<li>where <code>file</code> is the path to the file containing Monty byte code</li>
</ul></li>
<li>If the user does not give any file or more than one argument to your program, print the error message <code>USAGE: monty file</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>If, for any reason, it’s not possible to open the file, print the error message <code>Error: Can't open file &lt;file&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <code>&lt;file&gt;</code> is the name of the file</li>
</ul></li>
<li>If the file contains an invalid instruction, print the error message <code>L&lt;line_number&gt;: unknown instruction &lt;opcode&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <line_number> is the line number where the instruction appears.</line_number></li>
<li>Line numbers always start at 1</li>
</ul></li>
<li>The monty program runs the bytecodes line by line and stop if either:

<ul>
<li>it executed properly every line of the file</li>
<li>it finds an error in the file</li>
<li>an error occured</li>
</ul></li>
<li>If you can’t malloc anymore, print the error message <code>Error: malloc failed</code>, followed by a new line, and exit with status <code>EXIT_FAILURE</code>.</li>
<li>You have to use <code>malloc</code> and <code>free</code> and are not allowed to use any other function from <code>man malloc</code> (realloc, calloc, …)</li>
</ul>