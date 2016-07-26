/*=========================================================================

  Program:   ParaView
  Module:    vtkCPTensorFieldFunction.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkCPTensorFieldFunction - Abstract class for specifying tensor fields at points.
// .SECTION Description
// Abstract class for specifying tensor fields at specified points.  

#ifndef vtkCPTensorFieldFunction_h
#define vtkCPTensorFieldFunction_h

#include "vtkObject.h"
#include "vtkPVCatalystTestDriverModule.h" // needed for export macros

class VTKPVCATALYSTTESTDRIVER_EXPORT vtkCPTensorFieldFunction : public vtkObject
{
public:
  vtkTypeMacro(vtkCPTensorFieldFunction, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Get the NumberOfComponents.  This is abstract to make sure 
  // that the value for the NumberOfComponents cannot be changed.
  virtual unsigned int GetNumberOfComponents() = 0;

  // Description:
  // Compute the field value at Point.
  virtual double ComputeComponenentAtPoint(unsigned int component, double point[3],
                                           unsigned long timeStep, double time) = 0;

protected:
  vtkCPTensorFieldFunction();
  ~vtkCPTensorFieldFunction();

private:
  vtkCPTensorFieldFunction(const vtkCPTensorFieldFunction&) VTK_DELETE_FUNCTION;
  void operator=(const vtkCPTensorFieldFunction&) VTK_DELETE_FUNCTION;
};

#endif
