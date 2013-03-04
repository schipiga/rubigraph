#include "igraph.h"

void Init_igraph(){
  cIGraph = rb_define_class("IGraph", rb_cObject);

  rb_define_method(cIGraph, "shortest_path", m_shortest_path, 0);
}

VALUE m_shortest_path(VALUE self, VALUE from, VALUE to, VALUE matrix, VALUE weights, VALUE mode){
  igraph_t *graph;
  igraph_vector_t *wghts;
  igraph_neimode_t pmode = NUM2INT(mode);
  int pfrom = NUM2INT(from);
  int pto = NUM2INT(to);
  int i;
  int j;

  Data_Get_Struct(self, igraph_t, graph);

  for(i = 0; i < RARRAY_LEN(weights); i++){
    wghts[i] = NUM2DBL(RARRAY_PTR(weights)[i]);
  }

  igraph_get_shortest_path_dijkstra(graph,NULL,NULL,pfrom,pto,wghts,mode);
}
