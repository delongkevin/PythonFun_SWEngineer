#include "Node.h"

// PRQA S 3083 EOF // used by design


namespace me3d
{
  Node::Node()
    : skinIndex_s32(-1)
    , nodeType_e(e_NtEmpty)
    , name_o()
    , transformationMatrix_o()
    , combinedTransformMatrix_o()
    , previousCombinedTransformMatrix_o()
    , nodeSibling_po(NULL)
    , nodeFirstChild_po(NULL)
  {
  }

  Node::~Node()
  {

  }

  void Node::appendChild_v(Node* i_Parent_po, const Node* i_Child_po)
  {
    Node * pChildFrame = const_cast<Node*>(i_Parent_po->nodeFirstChild_po);
    if (pChildFrame == NULL)
    {
      i_Parent_po->nodeFirstChild_po = const_cast<Node*>(i_Child_po);
    }
    else
    {
      while (pChildFrame->nodeSibling_po)
      {
        pChildFrame = pChildFrame->nodeSibling_po;
      }

      pChildFrame->nodeSibling_po = const_cast<Node*>(i_Child_po);
    }
  }

  void Node::updateNodes_v(Node* i_Node_po, Node* i_Parent_po, Matrix4f& i_ParentMatrix_ro)
  {
    Assert(i_Node_po != NULL);

    i_Node_po->previousCombinedTransformMatrix_o = i_Node_po->combinedTransformMatrix_o;


    i_Node_po->combinedTransformMatrix_o = i_Node_po->transformationMatrix_o.mmulFast(i_ParentMatrix_ro);

   

    // transform siblings by the same matrix
    if (i_Node_po->nodeSibling_po)
    {
      updateNodes_v(i_Node_po->nodeSibling_po, i_Parent_po, i_ParentMatrix_ro );
    }

    // transform children by the transformed matrix - hierarchical transformation
    if (i_Node_po->nodeFirstChild_po)
    {
      updateNodes_v(i_Node_po->nodeFirstChild_po, i_Node_po, i_Node_po->combinedTransformMatrix_o);
    }
  }

  void Node::setupNodePointers_v(const std::vector<Node*>& i_Nodes_ro)
  {
    for (size_t i = 0; i < i_Nodes_ro.size(); ++i)
    {
      me3d::Node* v_Node_po = i_Nodes_ro[i];

      // 1) find node index
      sint32_t v_FirstChildIndex_s32  = findNodeIndex_s32(v_Node_po->nodeFirstChild_po, i_Nodes_ro);
      sint32_t v_NodeSiblingIndex_s32 = findNodeIndex_s32(v_Node_po->nodeSibling_po, i_Nodes_ro);

      // 2) add indices to Node class
      v_Node_po->nodeFirstChildIndex_s32 = v_FirstChildIndex_s32;
      v_Node_po->nodeSiblingIndex_s32    = v_NodeSiblingIndex_s32;
    }

    for (size_t i = 0; i < i_Nodes_ro.size(); ++i)
    {
      me3d::Node* v_Node_po = i_Nodes_ro[i];

      if (v_Node_po->nodeFirstChildIndex_s32 != -1)
      {
        v_Node_po->nodeFirstChild_po = i_Nodes_ro[v_Node_po->nodeFirstChildIndex_s32];
      }
      else
      {
        v_Node_po->nodeFirstChild_po = NULL;
      }

      if (v_Node_po->nodeSiblingIndex_s32 != -1)
      {
        v_Node_po->nodeSibling_po = i_Nodes_ro[v_Node_po->nodeSiblingIndex_s32];
      }
      else
      {
        v_Node_po->nodeSibling_po = NULL;
      }
    }
  }

  sint32_t Node::findNodeIndex_s32(const me3d::Node* i_Node_po, const std::vector<Node*>& i_Nodes_ro)
  {
    sint32_t v_Index_s32 = -1;

    for (size_t v_Current_s32 = 0; v_Current_s32 < i_Nodes_ro.size(); ++v_Current_s32)
    {
      if (i_Node_po == i_Nodes_ro[v_Current_s32])
      {
        // found valid index
        v_Index_s32 = static_cast<sint32_t>(v_Current_s32);
        break;
      }
    }

    return v_Index_s32;
  }

} // namespace me3d