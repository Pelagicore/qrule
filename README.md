QRuleEngine
===========
QRule Engine is a semantic rule engine that uses rules defined in a
domain specific language called QRule to verify semantic properties
of a target programming language, which in this case is QML.

The idea is to use QRuleEngine as a linter for QML where the rules
are defined by the users. This allows for features such as project
or customer specific rules.

Maintainer Viktor Sjölind (DunderRoffe at github)
Maintained at https://github.com/pelagicore/qrule

Build
-----
Make a directory to build QRuleEngine in.
Then, execute `cmake` towards the directory containing the `src` folder.
CMake needs to know were to look for Qt5 Qt5Core and Qt5Quick.
If those are not installed on the system but locally compiled you need
to point them out. Example of `CMAKE_PREFIX_PATH: ~/Qt/5.6/gcc_64/lib/cmake`

```bash
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=<path to Qt5 Qt5Core and Qt5Quick cmake> ..
make
```

External dependencies
---------------------
* Qt5

Usage
-----
The program takes two parameters:
1. The file defining the rules
2. A non-empty list of QML and JavaScript files to verify

```bash
./QRuleEngine <path to QRule file> [non-empty list of files to verify]
```

Example:
```bash
./QRuleEngine rules.kr qmlFile1.qml qmlFile2.qml qmlFile3.qml
```

QRule language
--------------
The QRule language is built around computational tree logic (CTL)
which is used to describe properties of tree structures. A rule file
consists of a comma separated list of rules. Each rule is defined
by a tag, severity level, cause for the rule, scope of the rule,
rule explanation and the actual CTL rule expression.

```
Tag Severity RuleCause ASTScope ?? Explanation :: CTL Expression
```

### Tag
A tag or name of the rule that will be in the output XML.
Exists purely in order to allow better filtering of the output XML.

### Severity
The severity if the rule is violated. The definition of what the
different severity levels mean are up to the users.
Exists purely in order to allow better filtering of the output XML.

Valid values: {Info, Warning, Critical}.

### RuleCause
Is this a policy or a limitation in the target language.
Exists purely in order to allow better filtering of the output XML.

Valid values: {Policy, Language}.

### ASTScope
The scope of the rule, should imported files verified as well or
is it just the file itself.

Valid values: {File, Imported}.

### Explanation
Text explanation of why this rule is relevant.
This is used only to be included as a verbose comment in the output
to describe why developers should care about this rule. Exists purely
in order to allow better fil# License and Copyright

Copyright (C) 2015 Pelagicore ABtering of the output XML.

### Expression
Computational Tree Logical expression used while verifying the rule.

Output
------
QRuleEngine outputs the results in a XML file called 'output.xml'.
The output lists rule violation occurrences per defined rule. This
means that all occurrences of violations to rule X will be listed
under X no matter in which file the violation occurred.

Example
-------
An example of an execution of QRuleEngine:

QRule file:
```QRule
"NoUnreferencedId" Critical Policy File
  ?? "All defined ids should be used at some point."
  :: forAll "ScriptBinding.ExpressionStatement.IdentifierExpression" :
       (!(V = "parent")) ->
         (EF((nodeType = "IdentifierExpression") & !(row = R) & (value = V))),

"LowerCaseLetterStartVarName" Critical Policy Imported
  ?? "It is awfully important to have all JavaScript
      variable names start with a lowercase letter"
  :: AG( (nodeType = "VariableDeclaration") -> (value match "[a-z]*")),
```

QML file:
```QML
import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    anchor.fill: parent
    id: ident1
    Item {
        function fname(a, b) {
               var Z = {asd: 123};
           }
    }
}
```

Produced output:
```XML
<?xml version="1.0" encoding="UTF-8"?>
<krule tag="LowerCaseLetterStartVarName" severity="Critical"
       astscope="Imported"       rulecause="Policy">
<occurrance row="10" col="20" filename="../testfiles/test.qml">
Z = {asd: 123}
</occurrance>
<explanation>
It is awfully important to have all JavaScript variable
 names start with a lowercase letter
</explanation>
</krule>
<krule tag="NoUnreferencedId" severity="Critical"
       astscope="File" rulecause="Policy">
<occurrance row="7" col="9" filename="../testfiles/test.qml">
ident1
</occurrance>
<explanation>
All defined ids should be used at some point.
</explanation>
</krule>
```

# License and Copyright
Copyright (C) 2016 Pelagicore AB

Please see LICENSE file for license. 
