/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// FooBar Widgets includes
#include "qSlicerEndoscopeCalibrationFooBarWidget.h"
#include "ui_qSlicerEndoscopeCalibrationFooBarWidget.h"

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_EndoscopeCalibration
class qSlicerEndoscopeCalibrationFooBarWidgetPrivate
  : public Ui_qSlicerEndoscopeCalibrationFooBarWidget
{
  Q_DECLARE_PUBLIC(qSlicerEndoscopeCalibrationFooBarWidget);
protected:
  qSlicerEndoscopeCalibrationFooBarWidget* const q_ptr;

public:
  qSlicerEndoscopeCalibrationFooBarWidgetPrivate(
    qSlicerEndoscopeCalibrationFooBarWidget& object);
  virtual void setupUi(qSlicerEndoscopeCalibrationFooBarWidget*);
};

// --------------------------------------------------------------------------
qSlicerEndoscopeCalibrationFooBarWidgetPrivate
::qSlicerEndoscopeCalibrationFooBarWidgetPrivate(
  qSlicerEndoscopeCalibrationFooBarWidget& object)
  : q_ptr(&object)
{
}

// --------------------------------------------------------------------------
void qSlicerEndoscopeCalibrationFooBarWidgetPrivate
::setupUi(qSlicerEndoscopeCalibrationFooBarWidget* widget)
{
  this->Ui_qSlicerEndoscopeCalibrationFooBarWidget::setupUi(widget);
}

//-----------------------------------------------------------------------------
// qSlicerEndoscopeCalibrationFooBarWidget methods

//-----------------------------------------------------------------------------
qSlicerEndoscopeCalibrationFooBarWidget
::qSlicerEndoscopeCalibrationFooBarWidget(QWidget* parentWidget)
  : Superclass( parentWidget )
  , d_ptr( new qSlicerEndoscopeCalibrationFooBarWidgetPrivate(*this) )
{
  Q_D(qSlicerEndoscopeCalibrationFooBarWidget);
  d->setupUi(this);
}

//-----------------------------------------------------------------------------
qSlicerEndoscopeCalibrationFooBarWidget
::~qSlicerEndoscopeCalibrationFooBarWidget()
{
}
