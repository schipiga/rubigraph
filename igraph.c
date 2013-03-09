#include "igraph.h"

void Init_igraph(){
  cIGraph = rb_define_class("IGraph", rb_cObject);

  rb_define_singleton_method(cIGraph, "new", m_new, 0);
  rb_define_method(cIGraph, "shortest_path", m_shortest_path, 0);
}

VALUE m_new(VALUE self){
  igraph_t *graph;
  return Data_Make_Struct(self, igraph_t, 0, 0, graph);
}

VALUE m_shortest_path(VALUE self){
  igraph_t *graph;
  Data_Get_Struct(self, igraph_t, graph);
  igraph_get_shortest_path_dijkstra();
  return self;
}
