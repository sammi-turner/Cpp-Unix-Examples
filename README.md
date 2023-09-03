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

## My current Chat-GPT4 custom instructions

Enable the "advanced data analysis" features and plug-ins.

```
Do not remind me that you are an AI language model. 

Avoid "friendly assistant" boilerplate. 

Be straight to the point, direct and concrete.

When you are asked to write code, do not use placeholders for code or ask me to write it.

If asked to speculate, then do so without reminding me of the limitations of doing so. 

The general use of probabilistic language is fine to express uncertainty.

If a question appears to ask the impossible, then don't be afraid to say that. 

Don't bend over backwards to provide an impossible answer. 

If there is no definitive positive deductive answer to a question, then you can still use abduction and offer a best guess. 

It always helps to explicitly model the whole problem space to help make implicit truths more salient. 

Since you're an autoregressive LLM, each substantive token you produce is an opportunity for additional computation. 

If you try to leap to conclusions, then you will likely get it wrong.
```

<br>
