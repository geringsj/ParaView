/*=========================================================================

  Program:   ParaView
  Module:    vtkSMAnimationSceneGeometryWriter.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSMAnimationSceneGeometryWriter - helper class to write
// animation geometry in a data file.
// .SECTION Description
// vtkSMAnimationSceneGeometryWriter is a concrete implementation of
// vtkSMAnimationSceneWriter that can write the geometry as a data file.
// This writer can only write the visible geometry in one view.

#ifndef vtkSMAnimationSceneGeometryWriter_h
#define vtkSMAnimationSceneGeometryWriter_h

#include "vtkPVAnimationModule.h" //needed for exports
#include "vtkSMAnimationSceneWriter.h"

class vtkSMProxy;

class VTKPVANIMATION_EXPORT vtkSMAnimationSceneGeometryWriter : public vtkSMAnimationSceneWriter
{
public:
  static vtkSMAnimationSceneGeometryWriter* New();
  vtkTypeMacro(vtkSMAnimationSceneGeometryWriter,
    vtkSMAnimationSceneWriter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Get/Set the View Module from which we are writing the 
  // geometry.
  vtkGetObjectMacro(ViewModule, vtkSMProxy);
  void SetViewModule(vtkSMProxy*);

protected:
  vtkSMAnimationSceneGeometryWriter();
  ~vtkSMAnimationSceneGeometryWriter();

  // Description:
  // Called to initialize saving.
  virtual bool SaveInitialize(int startCount);

  // Description:
  // Called to save a particular frame.
  virtual bool SaveFrame(double time);

  // Description:
  // Called to finalize saving.
  virtual bool SaveFinalize();

  vtkSMProxy* GeometryWriter;
  vtkSMProxy* ViewModule;
private:
  vtkSMAnimationSceneGeometryWriter(const vtkSMAnimationSceneGeometryWriter&) VTK_DELETE_FUNCTION;
  void operator=(const vtkSMAnimationSceneGeometryWriter&) VTK_DELETE_FUNCTION;
};

#endif
