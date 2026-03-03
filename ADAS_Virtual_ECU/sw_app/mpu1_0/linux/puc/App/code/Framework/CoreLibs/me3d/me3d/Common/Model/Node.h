#ifndef ME3D_NODE_H
#define ME3D_NODE_H

// PRQA S 2100 EOF // public members used here by design.

#include "MeclTypeDefs.h"
#include <vector>         

namespace me3d
{

enum NodeType_e
{
  e_NtEmpty = 0,
  e_NtSkeletonRoot,
  e_NtSkeletonLimb,
  e_NtSkeletonLimbNode,  
  e_NtSkeletonEffector,
  e_NtLight,
  e_NtCamera,
  e_NtMesh,
  e_NtMarker,
  e_NtNull,
  e_NtRoot
};

enum InheritanceType_e
{
  e_ItRrSs = 0,
  e_ItRSrs,
  e_ItRrs
};

class Node
{
public:
  Node();
  virtual ~Node();

  static void appendChild_v(Node* i_Parent_po, const Node* i_Child_po);
  static void updateNodes_v(Node* i_Node_po, Node* i_Parent_po, Matrix4f& i_ParentMatrix_ro);
  static void setupNodePointers_v(const std::vector<Node*>& i_Nodes_ro);
  static sint32_t findNodeIndex_s32(const me3d::Node* i_Node_po, const std::vector<Node*>& i_Nodes_ro);

  sint32_t    skinIndex_s32;

  NodeType_e  nodeType_e;
  MEString    name_o;
  Matrix4f    transformationMatrix_o;
  Matrix4f    combinedTransformMatrix_o;
  Matrix4f    previousCombinedTransformMatrix_o;

  Node*       nodeSibling_po;
  Node*       nodeFirstChild_po;
  sint32_t    nodeSiblingIndex_s32;
  sint32_t    nodeFirstChildIndex_s32;

  InheritanceType_e inheritanceType_e;
};

} // namespace me3d

#endif
