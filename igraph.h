#include <ruby.h>
#include <igraph/igraph.h>

VALUE cIGraph;

void Init_igraph();

VALUE m_shortest_path(VALUE self, VALUE from, VALUE to, VALUE matrix, VALUE weights, VALUE mode);
