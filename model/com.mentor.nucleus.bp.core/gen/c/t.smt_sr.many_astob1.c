T_b(ws);
T_b(te_set->module);
T_b(te_set->clear);
T_b("( ");
T_b(te_select_related->result_var);
T_b(" );\n");
T_b(ws);
T_b("{");
T_b(te_select_related->te_classGeneratedName);
T_b(" * ");
T_b(te_lnk->left);
T_b(";\n");
T_b(ws);
T_b(te_set->scope);
T_b(te_set->iterator_class_name);
T_b(" start_many_iterator;\n");
T_b(ws);
T_b(te_set->iterator_reset);
T_b("( &start_many_iterator, ");
T_b(te_select_related->start_var);
T_b(" );\n");
T_b(ws);
T_b("while ( 0 != ( ");
T_b(te_lnk->left);
T_b(" = (");
T_b(te_select_related->te_classGeneratedName);
T_b(" *) ");
T_b(te_set->module);
T_b(te_set->iterator_next);
T_b("( &start_many_iterator ) ) ) {\n");
if ( 0!=strcmp("",subtypecheck) ) {
T_b("  ");
T_b(subtypecheck);
T_b("\n");
}
T_b(ws);
T_b("  {");
T_b(te_lnk->te_classGeneratedName);
T_b(" * ");
T_b(te_lnk->linkage);
T_b(" = ");
T_b(te_lnk->left);
T_b("->");
T_b(te_lnk->linkage);
T_b(";\n");
T_b(ws);
T_b("  if ( ! ");
T_b(te_set->module);
T_b(te_set->contains);
T_b("( (");
T_b(te_set->scope);
T_b(te_set->base_class);
T_b(" *) ");
T_b(te_select_related->result_var);
T_b(", ");
T_b(te_lnk->linkage);
T_b(" ) ) {\n");
T_b(ws);
T_b("    ");
T_b(te_set->module);
T_b(te_set->insert_element);
T_b("( (");
T_b(te_set->scope);
T_b(te_set->base_class);
T_b(" *) ");
T_b(te_select_related->result_var);
T_b(", ");
T_b(te_lnk->linkage);
T_b(" );\n");
T_b(ws);
T_b("}}}}\n");
