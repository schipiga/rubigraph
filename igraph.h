#include <ruby.h>
#include <igraph/igraph.h>

VALUE cIGraph;

void Init_igraph();

VALUE m_shortest_path(VALUE self);

VALUE m_new(VALUE self);
