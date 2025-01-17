# SPDX-FileCopyrightText: Copyright (c) Kitware Inc.
# SPDX-License-Identifier: BSD-3-Clause

r"""collaboration is a helper module useful for handling synchronisation
in multi-client configuration as well as providing other collaboration
related methods

A simple example:
  from paraview import collaboration

  collaboration.processServerEvents()
"""

import paraview, re, types, sys, vtk
from paraview import servermanager

def processServerEvents():
  """Update the local state based on the notifications received from the server
  that have been generated by other clients."""
  if servermanager.ActiveConnection:
     session = servermanager.ActiveConnection.Session
     if session.IsMultiClients() and session.IsNotBusy():
        while servermanager.vtkProcessModule.GetProcessModule().GetNetworkAccessManager().ProcessEvents(100):
          pass
