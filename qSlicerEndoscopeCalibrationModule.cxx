/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// Qt includes
#include <QtPlugin>

// EndoscopeCalibration Logic includes
#include <vtkSlicerEndoscopeCalibrationLogic.h>

// EndoscopeCalibration includes
#include "qSlicerEndoscopeCalibrationModule.h"
#include "qSlicerEndoscopeCalibrationModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerEndoscopeCalibrationModule, qSlicerEndoscopeCalibrationModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerEndoscopeCalibrationModulePrivate
{
public:
  qSlicerEndoscopeCalibrationModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerEndoscopeCalibrationModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerEndoscopeCalibrationModulePrivate
::qSlicerEndoscopeCalibrationModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerEndoscopeCalibrationModule methods

//-----------------------------------------------------------------------------
qSlicerEndoscopeCalibrationModule
::qSlicerEndoscopeCalibrationModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerEndoscopeCalibrationModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerEndoscopeCalibrationModule::~qSlicerEndoscopeCalibrationModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerEndoscopeCalibrationModule::helpText()const
{
  return "This is a loadable module bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerEndoscopeCalibrationModule::acknowledgementText()const
{
  return "This work was was partially funded by NIH grant 3P41RR013218-12S1";
}

//-----------------------------------------------------------------------------
QStringList qSlicerEndoscopeCalibrationModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("Jean-Christophe Fillion-Robin (Kitware)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerEndoscopeCalibrationModule::icon()const
{
  return QIcon(":/Icons/EndoscopeCalibration.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerEndoscopeCalibrationModule::categories() const
{
  return QStringList() << "Examples";
}

//-----------------------------------------------------------------------------
QStringList qSlicerEndoscopeCalibrationModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerEndoscopeCalibrationModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerEndoscopeCalibrationModule
::createWidgetRepresentation()
{
  return new qSlicerEndoscopeCalibrationModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerEndoscopeCalibrationModule::createLogic()
{
  return vtkSlicerEndoscopeCalibrationLogic::New();
}
