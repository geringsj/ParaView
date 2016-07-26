/*=========================================================================

  Program:   ParaView
  Module:    vtkKdTreeGenerator.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkKdTreeGenerator - creates a vtkPKdTree using the partitioning
// information provided by a vtkExtentTranslator.
// generates the KdTree
// .SECTION Description
// vtkKdTreeGenerator is used to generate a KdTree using the partitioning
// information garnered from a vtkExtentTranslator (or subclass). Since we need
// spatial bounds for the KdTree, we assume that structured data corresponding
// to the vtkExtentTranslator is an ImageData with the provided spacing and
// origin.
// The algorithm used can be summarized as under:
// \li Inputs: * Extent Translator, * Number of Pieces
// \li Determine the bounds for every piece/region using the extent translator.
// \li Given a set of pieces (number of pieces > 1), we iteratively determine 
//     the plane along which the the pieces can be split into two 
//     non-intersecting non-empty groups. 
// \li If number of pieces in a set of regions = 1, then we create a leaf node
//     representing that region.
// \li If number of pieces > 1, a new non-leaf node is creates with children
//     as the subtree generated by repeating the same process on the 
//     two non-intersecting, non-empty groups of pieces.
//  
//  vtkKdTreeGenerator also needs to determine the assignment of regions to 
//  the processors. Since vtkPKdTree assigns Ids to the leaf nodes in inorder,
//  we can determine the assignment by assigning temporary ids to all
//  leaf nodes indication the piece number they represent and simply
//  traversing the tree in inorder, and recording only the leaf
//  IDs.

#ifndef vtkKdTreeGenerator_h
#define vtkKdTreeGenerator_h

#include "vtkObject.h"
#include "vtkPVVTKExtensionsRenderingModule.h" // needed for export macro

class vtkDataObject;
class vtkExtentTranslator;
class vtkInformation;
class vtkKdNode;
class vtkKdTreeGeneratorVector;
class vtkPKdTree;

class VTKPVVTKEXTENSIONSRENDERING_EXPORT vtkKdTreeGenerator : public vtkObject
{
public:
  static vtkKdTreeGenerator* New();
  vtkTypeMacro(vtkKdTreeGenerator, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Get/Set the kdtree which is updated in BuildTree.
  void SetKdTree(vtkPKdTree*);
  vtkGetObjectMacro(KdTree, vtkPKdTree);

  // Description:
  // Get/Set the number of pieces.
  vtkSetMacro(NumberOfPieces, int);
  vtkGetMacro(NumberOfPieces, int);

  // Description:
  // Builds the KdTree using the partitioning of the data.
  bool BuildTree(vtkExtentTranslator* translator, const int extents[6],
    const double origin[3], const double spacing[4]);

protected:
  vtkKdTreeGenerator();
  ~vtkKdTreeGenerator();

  // Description:
  // Get/Set the extent translator.
  void SetExtentTranslator(vtkExtentTranslator*);
  vtkGetObjectMacro(ExtentTranslator, vtkExtentTranslator);

  // Description:
  // Get/Set the whole extent of the data.
  vtkSetVector6Macro(WholeExtent, int);
  vtkGetVector6Macro(WholeExtent, int);

  // Description:
  vtkSetVector3Macro(Origin, double);
  vtkSetVector3Macro(Spacing, double);

  // Description:
  // Obtains information from the extent translator about the partitioning of
  // the input dataset among processes.
  void FormRegions();

  int FormTree(vtkKdNode* parent, vtkKdTreeGeneratorVector& regions_ids);
  int CanPartition(int division_point, int dimension,
  vtkKdTreeGeneratorVector& ids,
  vtkKdTreeGeneratorVector& left, vtkKdTreeGeneratorVector& right);

  // Converts extents to bounds in the kdtree.
  bool ConvertToBounds(vtkKdNode* node);

  vtkPKdTree* KdTree;
  vtkExtentTranslator* ExtentTranslator;

  double Origin[3];
  double Spacing[3];

  int WholeExtent[6];
  int NumberOfPieces;

  int *Regions;
private:
  vtkKdTreeGenerator(const vtkKdTreeGenerator&) VTK_DELETE_FUNCTION;
  void operator=(const vtkKdTreeGenerator&) VTK_DELETE_FUNCTION;
};


#endif

