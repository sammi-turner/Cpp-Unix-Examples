<br>

# Unix C++ Examples

Small example programs for MacOS and Linux.

<br>

## Key Value Pair Thing 

This utility is a shortcut for storing key-value pairs as sqlite tables, for updating them and for querying their values.

<br>

## List editor

This app implements basic [CRUD operations](https://en.wikipedia.org/wiki/Create,_read,_update_and_delete) on lists, in addition to 'swap', 'copy', 'cut', 'paste', 'insert', 'load', 'save', and 'exit'.

To return to the main menu, simply enter a blank input.

<br>

## Yahtzee

A solitaire, command line version of the [famous dice game](https://en.wikipedia.org/wiki/Yahtzee).

<br>

## Expression evaluator

An arithmetic expression evaluator.

<br>

## Rationals demo

A mechanism for rational number arithmetic, without using floats.

<br>

## AI Code Generation

Large Language Models (LLMs) are only effective for me because I don't trust their output.

I always test the code that they generate!

However, given that C++ is a very mature language, there is a suprising amount of training data available.

<br>

## Function Generation With LLMs

I have had good results with prompts using the following template

```
"Write a [name] function in C++ that takes [name the parameters and their types] 
and returns a [type] such that [describe what the function does]."
```

<br>

## Hacking the context window limit

Although feeding errors back to Chat-GPT4 can yield good results, sometimes a conversation will drag on so long that the LLM "forgets" what you are talking about and the chatbots answers rapidly become useless.

This is because of a fundamental limit built into the LLM. Namely the maximum size of its context window. The size of the context grows as the conversation progresses.

To avoid running up against this limit when you are working on a code generation task, simply delete the chat you are using, start a new one, attach the source code that needs fixing to the chat (the "Advanced Data Analytics" plugin should be enabled), tell the chatbot that there are syntax errors or unexpected behaviour and ask for its help.

This process can be repeated as often as necessary!

<br>
