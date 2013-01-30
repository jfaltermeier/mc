---

Copyright 2013 Mentor Graphics Corporation

---

xtUML Project Design Note

Instance Dumping and Model Compiler Speed-Up


1.  Abstract
------------
Instance loading and dumping capability in the model compiler will be
added/enhanced to improve translation speed.  The OAL translation
functionality will migrate from RSL to xtUML.


2.  History
-----------


3.  Document References
-----------------------
[1] Issues 4 <https://github.com/xtuml/mc/issues/4>
    Create instance dumper for C model compiler.
[2] Analysis Note <https://github.com/xtuml/mc/doc/notes/4_cds_instdump_ant.md>


4.  Background
--------------
See [2].


5.  Analysis
------------
See [2].


6.  Requirements
----------------
See [2].


7.  Design
----------

### 7.1 Packaging
There are several alternatives for packaging the OAL/RSL into
action bodies.  The two most compelling are functions and operations.

#### 7.1.1  Pros and Cons of Packaging Alternatives
Functional cohesion would dictate allocating processing to classes packaged
into class operations.  This would keep functionality in close proximity
to the data being operated upon.  However class operations are more widely
distributed in the model and thus separated from related action language
bodies allocated to other classes.

Functions have a more direct mapping to a set of RSL archetype files.
They are easier to see and edit in the xtUML Editor.  It should not be
difficult to reallocate the functions to operations in the future.

We will start with OAL functions with very close mapping to the RSL.


### 7.2 File Naming
The name of an archetype file needs to be easy to generate.  The
model of the model compiler will have the information needed to
generate the RSL file.

It may be simpler to use fewer archetype files.  However, the
ordering of the functions in the archetype files might then be a
challenge.

<TE_keyletters>_<operation_name>
The operation name may have a (sub)pattern.

6.1.1 Function Name Pattern
The function can be marked with a file name that will carry the contents
of the fuction.  The Description field of the function can be given an RSL


The function can be marked with a file name that will carry the contents
of the fuction.  The Description field of the function can be given an RSL
parse keyword pair to name the file (e.g. file:sys.arc).
  

Migrate (RSL->OAL), gen (OAL->RSL), compare (gen'd RSL to edited RSL),
replace (edited RLS with OAL/gen'd RSL) little by little

RSL model compiler:  param ordering, invoke?, param labeling
Relates need refs in a comment, bridge or actual (until RSL MC generates them).

Consider RSL MC that uses Action_Semantics versus traversing/iterating ACT_SMTs.
  .invoke r = f(); .assign x = r.result;
  return x; -> .assign attr_result = x



Remove domain_CLASS_INFO_INIT macro and simply put the data in the C file.
  batch_relater_init
  instance_loaders
  dispatchers

Each class is going to need an instance dumper.
  Maybe it should link into class_info.
  Each data types will have a dumper.
  Each attribute will call the associated data type dumper.

Consider defining a class to carry a file name and file contents.
Use this in conjunction with emit-to-file.
This seems especially appropriate when percolating templates up
through several layers of invocation/stack.

Use call by reference rather than the attr_ strangeness.
The call-by-reference mechanism will closely map between OAL
and RSL.  Consider passing in the instance that will contain the
output values.

Basically make the RSL actions, functional allocation and file
naming look as much like the model as feasible.
  - Use OAL style in the RSL.
  - Use a precise mapping for the names of the operations.
  - Pass the same argument names.

Edit docgen to explore.
Functionize (OAL) beginning of 3020.
Test in RSL-only first.
Rid more transients.



7. Work Required
----------------

7.1 Relate Statements
RSL does not have relate; it simply copies identifiers into referential
attributes.  The OAL will do both until an RSL model compiler automates
the generation of the foreign key copy statements.

7.2 Parameter Naming and Labeling
7.2 RSL Invoke Statement


sys.arc (easy) [TE_SYS]
  Package as function unless emit-to-file prevents it.

marking (hard) [TM_?]
  Somehow support marking, probably using the same marking files,
  but maybe not.

factory_factory (easy but option to improve) [TE_SYS + lots of singletons]
  This has a ton of subroutines that will easily turn
  into operations on the various classes.  However, this
  really should be some kind of loadable text file.

q.assoc.pseudoformalize.arc (easy) [TE_REL]
  This has PseudoFormalizeUnformalizedAssociations.

MC_metamodel_populate (big) [TE_SYS]
  Should this be made hierarchical with operations delegated down?
  Yes, we should at least break it out as it is now.
  All of the functions invoked from this query are fairly OALish.

q.domain.analyze.arc (easy) [TE_C?]
  Turn this into an operation that calls other operations.

a.oal.analyze.arc (medium) [TE_ABA or TE_SMT]
  This contains the various operations called by q.domain.analyze.arc.
  These should be placed onto the appropriate TE_ classes.

CreateSpecialWhereClauseInstances (easy) [TE_SWC]
  Called from sys.arc, defined in q.oal.analyze.arc.

te_c_CollectLimits (easy) [TE_C]
  simple roll-up

translate_all_oal (easy) [TE_ABA]

q.oal.translate.arc (easy) [TE_ABA] 4

q.smt.generate.arc (easy except for select_related) [TE_SMT] 69
  Select related is huge.

t.smt.c (difficult) [TE_SMT] 29
  Consider making these into "real" templates.

q.val.translate.arc (easy but long) [TE_VAL] 34


8.  Design Comments
-------------------

9.  Work Required
-----------------

10.  Unit Test
--------------



End
---