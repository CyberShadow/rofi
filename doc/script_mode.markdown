# Script mode


## Header entry

Extra entries can be passed using a header.
Header entries start with '\0' and uses '\x1f' as separator.

```
echo -e "\0message\x1fMessage bar"
echo -e "\0urgent\x1f1-3"
```

 * `message`: Set the message bar (utf-8).
 * `urgent`:  Pass list of rows that should be marked urgent.
 * `active`:  Pass list of rows that should be marked active.
 * `markup-rows`: Rows are formatted using pango markup.
 * `prompt`:  Set the prompt (utf-8).

### Active,Urgent list

You can specify single element:  3
A range: 3-8
or a set of rows:  0,2
or any combination:  0,2-3,9

