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
#include <QDebug>

// SlicerQt includes
#include "qSlicerEndoscopeCalibrationModuleWidget.h"
#include "ui_qSlicerEndoscopeCalibrationModuleWidget.h"

// SlicerQt includes
#include "qSlicerApplication.h"
#include "qSlicerLayoutManager.h"
#include "qSlicerWidget.h"

// Qt includes
#include <QApplication>
#include <QTimer>

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerEndoscopeCalibrationModuleWidgetPrivate: public Ui_qSlicerEndoscopeCalibrationModuleWidget
{
public:
  qSlicerEndoscopeCalibrationModuleWidgetPrivate();
};

//-----------------------------------------------------------------------------
// qSlicerEndoscopeCalibrationModuleWidgetPrivate methods

//-----------------------------------------------------------------------------
qSlicerEndoscopeCalibrationModuleWidgetPrivate::qSlicerEndoscopeCalibrationModuleWidgetPrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerEndoscopeCalibrationModuleWidget methods

//-----------------------------------------------------------------------------
qSlicerEndoscopeCalibrationModuleWidget::qSlicerEndoscopeCalibrationModuleWidget(QWidget* _parent)
  : Superclass( _parent )
  , d_ptr( new qSlicerEndoscopeCalibrationModuleWidgetPrivate )
{
}

//-----------------------------------------------------------------------------
qSlicerEndoscopeCalibrationModuleWidget::~qSlicerEndoscopeCalibrationModuleWidget()
{
}

//-----------------------------------------------------------------------------
void qSlicerEndoscopeCalibrationModuleWidget::setup()
{
  Q_D(qSlicerEndoscopeCalibrationModuleWidget);
  d->setupUi(this);
  this->Superclass::setup();
    
  connect(d->VideoON, SIGNAL(toggled(bool)),
       this, SLOT(onVideoONToggled(bool)));
    
  // QTimer setup
  t = new QTimer();
  this->timerFlag = 0;
  connect(t,SIGNAL(timeout()),this,SLOT(timerIntrupt()));
    
    
}

//-----------------------------------------------------------------------------
void qSlicerEndoscopeCalibrationModuleWidget::timerIntrupt()
{
    Q_D(qSlicerEndoscopeCalibrationModuleWidget);
    
    if(this->timerFlag == 1)
    {
        //this->CameraHandler();
    }
    
}

//-----------------------------------------------------------------------------
void qSlicerEndoscopeCalibrationModuleWidget::onVideoONToggled(bool checked)
{
    Q_D(qSlicerEndoscopeCalibrationModuleWidget);
    
    if(checked)
    {
        CvCapture* capture;
        
        // Open /dev/video0
        capture = cvCaptureFromCAM(0);
        
        assert( capture != NULL);
        
        cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240);
        cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320);
        cvSetCaptureProperty(capture, CV_CAP_PROP_FPS,30);
        
        IplImage* bgr_frame = cvQueryFrame( capture );
        
        cvNamedWindow( "Endoscope calibration", CV_WINDOW_NORMAL);
        
        while( ((bgr_frame = cvQueryFrame( capture )) != NULL) && checked)
        {
            // Display image on OpenCV window
            cvShowImage( "Endoscope calibration", bgr_frame);
            char c = cvWaitKey(33);
            if( c == 27 ) break;
        }
        
        d->VideoON->setChecked(false);
        d->VideoOFF->setChecked(true);
        
        cvReleaseCapture(&capture);
        cvDestroyWindow( "Endoscope calibration" );
    }
}


