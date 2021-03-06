//------------------------------------------------------------------------------
//  simpletreetest.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "simpletreetest.h"
#include "util/simpletree.h"
#include "util/string.h"

namespace Test
{
__ImplementClass(Test::SimpleTreeTest, 'STTT', Test::TestCase);

using namespace Util;

//------------------------------------------------------------------------------
/**
*/
void
SimpleTreeTest::Run()
{
    // create a tree of strings
    SimpleTree<String> tree;

    // populate first level of tree
    tree.Root().Append("Node1");
    tree.Root().Append("Node2");
    tree.Root().Append("Node3");

    // populate second level of tree
    tree.Root()[0].Append("Node11");
    tree.Root()[0].Append("Node12");

    tree.Root()[1].Append("Node21");

    tree.Root()[2].Append("Node31");
    tree.Root()[2].Append("Node32");
    tree.Root()[2].Append("Node33");

    // populate third level of tree
    tree.Root()[0][0].Append("Node111");
    tree.Root()[0][0].Append("Node112");
    tree.Root()[0][1].Append("Node121");

    tree.Root()[1][0].Append("Node211");
    tree.Root()[1][0].Append("Node212");
    tree.Root()[1][0].Append("Node213");

    tree.Root()[2][0].Append("Node311");
    tree.Root()[2][2].Append("Node331");

    // verify contents
    VERIFY(!tree.Root().HasParent());
    VERIFY(tree.Root().Size() == 3);
    const SimpleTree<String>::Node& node1 = tree.Root()[0];
    const SimpleTree<String>::Node& node2 = tree.Root()[1];
    const SimpleTree<String>::Node& node3 = tree.Root()[2];
    VERIFY(node1.HasParent());
    VERIFY(&tree.Root() == &node1.Parent());
    VERIFY(node1.Value() == "Node1");
    VERIFY(node2.Value() == "Node2");
    VERIFY(node3.Value() == "Node3");
    VERIFY(node1.Size() == 2);
    VERIFY(node2.Size() == 1);
    VERIFY(node3.Size() == 3);

    VERIFY(node1.Front().Value() == "Node11");
    VERIFY(node1.Back().Value() == "Node12");
    
    // delete some stuff
    tree.Root()[1].Clear();
    VERIFY(tree.Root()[1].IsEmpty());
    VERIFY(tree.Root()[1].Size() == 0);
}

} // namespace Test