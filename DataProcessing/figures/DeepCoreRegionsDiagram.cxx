//**********************************************************************
// D. Jason Koskinen
// 7/22/2015
//
// The following code plots the overhead and sideview of DeepCore for
// the actual IC79 and IC86-1,2,3 setups.
//**********************************************************************

#include "TCanvas.h"
#include "TLatex.h"
#include "TBox.h"
#include "TLine.h"
#include "TStyle.h"
#include "TCurlyLine.h"
#include "TArc.h"
#include "TCurlyArc.h"
#include "TArrow.h"
#include "TPolyLine.h"
#include "TMarker.h"
#include "TMath.h"

#include<iostream>
#include<vector>

int COLOR = kYellow+1;
int COLOR_IC79 = kRed+2;
int COLOR_TWOLAYER = kGray+2;

using namespace std;

void overHead( string geo);
void below( string geo);

void DeepCoreRegionsDiagram(){

  string geometry = "IC86EDC";
  //string geometry = "IC86";
  TCanvas *c1 = new TCanvas("c1", "A canvas", 0, 0, 600, 1200);
  c1->Range( 0, 0, 1350, 2*1300);

  overHead( geometry);
  below( geometry);

  string saveFileName = geometry + "_DeepCoreDiagram.pdf";
  c1->SaveAs( saveFileName.c_str());

  saveFileName = geometry + "_DeepCoreDiagram.eps";
  c1->SaveAs( saveFileName.c_str());


}

void overHead( string geometry){

  double  xOverHeadOffset = 1350/2 - 80;
  double  yOverHeadOffset = 1300/2 + 1300;

  //******************************
  //******************************
  // DeepCore Outline

  TPolyLine pline;
  pline.SetLineStyle(1);
  pline.SetLineWidth(6);
  pline.SetFillColor(COLOR);


  double xStart = 3 - 45/2 + xOverHeadOffset;
  double yStart = -150 - 117/2 + yOverHeadOffset;
  double xStep = 124;
  double yStep = 20.2;

  double yLayer = 117;
  double xLayer = 45;

  double xStart_EDC = 3 - 45/2 - xStep + xOverHeadOffset;
  double yStart_EDC = -150 - 117/2 -yStep + yOverHeadOffset;

  double xStart_TwoLayer = 3 - 45/2 - 2*xStep + xOverHeadOffset;
  double yStart_TwoLayer = -150 - 117/2 - 2*yStep + yOverHeadOffset;

  vector<double>  x1, x1_EDC, x1_TwoLayer;
  vector<double> y1, y1_EDC, y1_TwoLayer;
  
  //Outline for the 2-layer veto

  xStart_TwoLayer = (3 - 45/2 + xOverHeadOffset) - (1)*xStep - 45;
  yStart_TwoLayer = (-150 - 117/2  + yOverHeadOffset) - (1)*yStep - 117;
  
  cout << xStart_TwoLayer << endl;
  cout << yStart_TwoLayer << endl;
  
  x1_TwoLayer.push_back( xStart_TwoLayer);//Bottom most point
  x1_TwoLayer.push_back( xStart_TwoLayer + (1+2.5)*xStep);//bottom right
  x1_TwoLayer.push_back( xStart_TwoLayer + (1+2.5)*xStep + (1+2.5)*45);//right most
  x1_TwoLayer.push_back( xStart_TwoLayer + (0+2)*xStep + (2+3)*45);//top right
  
  x1_TwoLayer.push_back( xStart_TwoLayer + 5*xLayer);//Done
  x1_TwoLayer.push_back( xStart_TwoLayer + 6*xLayer - xStep);//
  x1_TwoLayer.push_back( xStart_TwoLayer + 6*xLayer - 2.5*xStep);//
  x1_TwoLayer.push_back( xStart_TwoLayer + 2.5*xLayer - 2.5*xStep);
  x1_TwoLayer.push_back( xStart_TwoLayer);
  
  y1_TwoLayer.push_back( yStart_TwoLayer);//Bottom most
  y1_TwoLayer.push_back( yStart_TwoLayer + (1+2.5)*yStep);// Bottom right
  y1_TwoLayer.push_back( yStart_TwoLayer + (1+2.5)*yStep + (1+2.5)*117);// right most
  y1_TwoLayer.push_back( yStart_TwoLayer + (0+2)*yStep + (2+3)*117);//top right
  
  y1_TwoLayer.push_back( yStart_TwoLayer + 5*yLayer);//Done
  y1_TwoLayer.push_back( yStart_TwoLayer + 6*yLayer - yStep);//
  y1_TwoLayer.push_back( yStart_TwoLayer + 6*yLayer - 2.5*yStep);//
  y1_TwoLayer.push_back( yStart_TwoLayer + 2.5*yLayer - 2.5*yStep);
  y1_TwoLayer.push_back( yStart_TwoLayer);
  
  TPolyLine plineTwoLayer;
  plineTwoLayer.SetLineStyle(5);
  plineTwoLayer.SetLineWidth(4);
  plineTwoLayer.SetLineColor(COLOR_TWOLAYER);
  plineTwoLayer.SetFillColor(0);
  
  plineTwoLayer.DrawPolyLine( x1_TwoLayer.size(), &x1_TwoLayer.at(0), &y1_TwoLayer.at(0), "f");
  plineTwoLayer.DrawPolyLine( x1_TwoLayer.size(), &x1_TwoLayer.at(0), &y1_TwoLayer.at(0));
  
  // Outline of the EDC volume
  
    xStart_EDC = 3 - 45/2 - xStep + xOverHeadOffset;
    yStart_EDC = -150 - 117/2 - yStep + yOverHeadOffset;

    x1_EDC.push_back( xStart_EDC);
    x1_EDC.push_back( xStart_EDC + 2.5*xStep);
    x1_EDC.push_back( xStart_EDC + 2.5*xStep + 2.5*45);
    x1_EDC.push_back( xStart_EDC + 2*xStep + 3*45);

    x1_EDC.push_back( xStart_EDC + 3*45);
    x1_EDC.push_back( xStart_EDC + 3*45 - 79);
    x1_EDC.push_back( xStart_EDC + 4*45 - 1.5*xStep);
    x1_EDC.push_back( xStart_EDC - 1.5*79);
    x1_EDC.push_back( xStart_EDC);
    
    y1_EDC.push_back( yStart_EDC);
    y1_EDC.push_back( yStart_EDC + 2.5*yStep);
    y1_EDC.push_back( yStart_EDC + 2.5*yStep + 2.5*117);
    y1_EDC.push_back( yStart_EDC + 2*yStep + 3*117);

    y1_EDC.push_back( yStart_EDC + 3*117);
    y1_EDC.push_back( yStart_EDC + 3*117 + 96.8);
    y1_EDC.push_back( yStart_EDC + 4*117 - 1.5*yStep);
    y1_EDC.push_back( yStart_EDC + 1.5*96.8);
    y1_EDC.push_back( yStart_EDC);

    pline.DrawPolyLine( x1_EDC.size(), &x1_EDC.at(0), &y1_EDC.at(0), "f");
    pline.SetLineColor( kBlue);
    pline.DrawPolyLine( x1_EDC.size(), &x1_EDC.at(0), &y1_EDC.at(0));


    x1.push_back( xStart);
    x1.push_back( xStart + 1.5*xStep);
    x1.push_back( xStart + 1.5*xStep + 1.5*45);
    x1.push_back( xStart + 3*45);
    x1.push_back( xStart + 3*45 - 1.5*xStep);
    x1.push_back( xStart - 1.5*79);
    x1.push_back( xStart);
    
    y1.push_back( yStart);
    y1.push_back( yStart + 1.5*yStep);
    y1.push_back( yStart + 1.5*yStep + 1.5*117);
    y1.push_back( yStart + 3*117);
    y1.push_back( yStart + 3*117 - 1.5*yStep);
    y1.push_back( yStart + 1.5*96.8);
    y1.push_back( yStart);

    pline.SetLineColor(COLOR_IC79);
    pline.SetLineStyle(2);
    pline.DrawPolyLine( x1.size(), &x1.at(0), &y1.at(0));



  //******************************
  //******************************
  // Draw DOMs

  TMarker m1_1;
  m1_1.SetMarkerStyle(20);
  m1_1.SetMarkerSize(1.3);
  m1_1.SetMarkerColor( kBlack);

  for( int i=0; i < 5; ++i){
    m1_1.DrawMarker( -571 + 79*i + xOverHeadOffset, -133 - 96.8*i + yOverHeadOffset);
  }

  TMarker m1;
  m1.SetMarkerStyle(20);
  m1.SetMarkerSize(1.3);

  for( int i=0; i < 6; ++i){
    m1.DrawMarker( -526 + 79*i + xOverHeadOffset, -16 - 96.8*i + yOverHeadOffset);
  }
  for( int i=0; i < 7; ++i){
    m1.DrawMarker( -481 + 79*i + xOverHeadOffset, 101 - 96.8*i + yOverHeadOffset);
  }
  for( int i=0; i < 8; ++i){
    m1.DrawMarker( -571 + 45*3 + 79*i + xOverHeadOffset, -133 + 117*3 - 96.8*i + yOverHeadOffset);
  }
  for( int i=0; i < 9; ++i){
    m1.DrawMarker( -571 + 45*4 + 79*i + xOverHeadOffset, -133 + 117*4 - 96.8*i + yOverHeadOffset);
  }
  for( int i=0; i < 10; ++i){
    m1.DrawMarker( -571 + 45*5 + 79*i + xOverHeadOffset, -133 + 117*5 - 96.8*i + yOverHeadOffset);
  }
  for( int i=1; i < 10; ++i){
    m1.DrawMarker( -571 + 45*6 + 79*i + xOverHeadOffset, -133 + 117*6 - 96.8*i + yOverHeadOffset);
  }
  for( int i=2; i < 10; ++i){
    m1.DrawMarker( -571 + 45*7 + 79*i + xOverHeadOffset, -133 + 117*7 - 96.8*i + yOverHeadOffset);
  }
  for( int i=3; i < 10; ++i){
    m1.DrawMarker( -571 + 45*8 + 79*i + xOverHeadOffset, -133 + 117*8 - 96.8*i + yOverHeadOffset);
  }
  for( int i=5; i < 10; ++i){
    m1.DrawMarker( -571 + 45*9 + 79*i + xOverHeadOffset, -133 + 117*9 - 96.8*i + yOverHeadOffset);
  }
  for( int i=6; i < 10; ++i){
    m1.DrawMarker( -571 + 45*10 + 79*i + xOverHeadOffset, -133 + 117*10 - 96.8*i + yOverHeadOffset);
  }

  TMarker m2;
  m2.SetMarkerColor(COLOR_IC79);
  m2.SetMarkerStyle(3);
  m2.SetMarkerSize(1.4);

  m2.DrawMarker( 41 + xOverHeadOffset, 35 + yOverHeadOffset);
  m2.DrawMarker( 107 + xOverHeadOffset, 15 + yOverHeadOffset);
  m2.DrawMarker( 113 + xOverHeadOffset, -60.5 + yOverHeadOffset);
  m2.DrawMarker( 57.2 + xOverHeadOffset, -105.5 + yOverHeadOffset);
  m2.DrawMarker( -9.9 + xOverHeadOffset, -79.6 + yOverHeadOffset);
  m2.DrawMarker( -11.1 + xOverHeadOffset, 6.6 + yOverHeadOffset);

  TMarker m3;
  m3.SetMarkerStyle(22);
  m3.SetMarkerColor(kBlue);
  m3.SetMarkerSize(1.5);
  m3.DrawMarker( 72 + xOverHeadOffset, -66.8 + yOverHeadOffset);
  m3.DrawMarker( 31 + xOverHeadOffset, -73.2 + yOverHeadOffset);


  double dist = 0;
  for( UInt_t i=0; i< x1.size() - 1; ++i){
    dist = TMath::Sqrt( TMath::Power( (x1.at(i) - x1.at(i+1)), 2) +
			TMath::Power( (y1.at(i) - y1.at(i+1)), 2));

    cout << dist << endl;
  }


  //**********************************************************************
  //**********************************************************************
  // Legend

  yOverHeadOffset -= 1400/2;
  double xLegendOffset = 920;

  TLatex tl;
  tl.SetTextAlign(12);
  tl.SetTextSize(0.05);

  tl.SetTextColor(kGray+2);
  tl.DrawLatex(30, 2540, "Top View");

  TBox *box = new TBox();
  box = new TBox( xLegendOffset, 0 + yOverHeadOffset, 1330, 220 + yOverHeadOffset); box->SetFillColor(0); box->Draw("l");

  tl.SetTextColor(kBlack);
  tl.SetTextSize( 0.025);
  tl.DrawLatex( xLegendOffset + 50, 190 + yOverHeadOffset, "IceCube Strings");
  tl.DrawLatex( xLegendOffset + 50, 150 + yOverHeadOffset, "HQE DeepCore Strings");
  tl.DrawLatex( xLegendOffset + 50, 110 + yOverHeadOffset, "DeepCore Infill Strings");
  tl.DrawLatex( xLegendOffset + 50, 70  + yOverHeadOffset, "(Mix of HQE and");
  tl.DrawLatex( xLegendOffset + 50, 30  + yOverHeadOffset, "normal DOMs)");

  m1.DrawMarker( xLegendOffset + 20, 190 + yOverHeadOffset);
  m2.DrawMarker( xLegendOffset + 20, 150 + yOverHeadOffset);
  m3.DrawMarker( xLegendOffset + 20, 110 + yOverHeadOffset);

  tl.SetTextSize( 0.02);

  tl.SetTextSize( 0.04);
  tl.SetTextAngle( 9);
  tl.SetTextColor(kYellow+4);
  //  tl.DrawLatex( 30 + xOverHeadOffset, 857 + yOverHeadOffset, "DeepCore");

  tl.SetTextSize( 0.03);
  tl.SetTextAngle( 9);
  tl.SetTextColor(COLOR_TWOLAYER);
  tl.DrawLatex( 10 + xOverHeadOffset, 909 + yOverHeadOffset, "IC86 Two Layer");

  tl.SetTextSize( 0.033);
  tl.SetTextColor(COLOR_IC79);
  tl.DrawLatex( -12 + xOverHeadOffset, 790 + yOverHeadOffset, "IC79");
  tl.SetTextColor(kBlue);
  tl.DrawLatex( -160 + xOverHeadOffset, 815 + yOverHeadOffset, "IC86");

}





void below( string geometry){

  double  yBelowOffset = 1300;
  double detHeight = 1270;

  TMarker td;
  td.SetMarkerStyle(20);
  td.SetMarkerSize(0.8);

  TLine tLine;
  tLine.SetLineColor(kGray);
  vector<double> xStringPos;


  //******************************
  //******************************
  // DeepCore Outlines

  TBox *box;
  TLatex tlatex;

  Double_t leftEdge;
  if( geometry.compare( "IC86EDC") == 0){
    leftEdge = 330;

    //test code for shading.

    // box = new TBox( leftEdge, yBelowOffset - detHeight*0.29, 831, yBelowOffset - detHeight*0.4); box->SetFillColor(COLOR); 
    // box->Draw("l");
    // box = new TBox( leftEdge, yBelowOffset - detHeight*0.64, 831, yBelowOffset - detHeight); box->SetFillColor(COLOR); 
    // box->Draw("l");
    
    // COLOR = kGray+3;
    // box = new TBox( 0, yBelowOffset - detHeight*0.52, 1350, yBelowOffset - detHeight*0.62); box->SetFillColor(COLOR); 
    // box->SetFillStyle(3013);
    // box->Draw("f");
    
    
  }
  else{
    leftEdge = 457;
  }
  
  box = new TBox( leftEdge, yBelowOffset - detHeight*0.29, 831, yBelowOffset - detHeight*0.4); box->SetFillColor(COLOR); 
  box->Draw("l");
  box = new TBox( leftEdge, yBelowOffset - detHeight*0.64, 831, yBelowOffset - detHeight); box->SetFillColor(COLOR); 
  box->Draw("l");

  COLOR = kGray+3;
  box = new TBox( 0, yBelowOffset - detHeight*0.52, 1350, yBelowOffset - detHeight*0.62); box->SetFillColor(COLOR); 
  box->SetFillStyle(3013);
  box->Draw("f");

  box = new TBox( 1090, 553, 1275, 592); box->SetFillColor(0);
  box->Draw("f");
  tlatex.SetTextSize( 0.025);
  tlatex.DrawLatex( 1100,  yBelowOffset - detHeight*0.58, "Dust Layer");


  //******************************
  //******************************
  // IceCube DOMS
  xStringPos.push_back( 148);
  xStringPos.push_back( 272);
  xStringPos.push_back( 396);
  xStringPos.push_back( 520);
  xStringPos.push_back( 768);
  xStringPos.push_back( 892);

  tLine.DrawLine( xStringPos.at(0), 1820, xStringPos.at(0), 1325);
  tLine.DrawLine( xStringPos.at(1), 1840, xStringPos.at(1), 1325);
  tLine.DrawLine( xStringPos.at(2), 1860, xStringPos.at(2), 1325);
  tLine.DrawLine( xStringPos.at(3), 1880, xStringPos.at(3), 1325);
  tLine.DrawLine( xStringPos.at(4), 1920, xStringPos.at(4), 1325);
  tLine.DrawLine( xStringPos.at(5), 1940, xStringPos.at(5), 1325);


  for( UInt_t j=0; j < xStringPos.size(); ++j){
    for( int i=0; i < 60; ++i){
      td.DrawMarker( xStringPos.at(j), yBelowOffset - (detHeight/60)*i);
    }
  }


  //******************************
  //******************************
  // DeepCore DOMS

  td.SetMarkerStyle(3);
  td.SetMarkerColor(COLOR_IC79);

  xStringPos.clear();

  xStringPos.push_back(585);
  xStringPos.push_back(652);
  xStringPos.push_back(707);

  tLine.DrawLine( xStringPos.at(0),1855, xStringPos.at(0), 936);
  tLine.DrawLine( xStringPos.at(1),1830, xStringPos.at(1), 936);
  tLine.DrawLine( xStringPos.at(2),1862, xStringPos.at(2), 936);

  for( UInt_t j=0; j < xStringPos.size(); ++j){
    for( int i=0; i < 10; ++i){
      td.DrawMarker( xStringPos.at(j), yBelowOffset - detHeight*0.3 - (detHeight/100)*i);
    }
    for( int i=0; i < 50; ++i){
      td.DrawMarker( xStringPos.at(j), yBelowOffset - detHeight*0.65 + 7 - (detHeight/(1000./7.))*i);
    }
  }

  //******************************
  //******************************
  // InFill DOMS
  td.SetMarkerStyle(22);
  td.SetMarkerColor(kBlue);

  xStringPos.clear();
  xStringPos.push_back(627);
  xStringPos.push_back(666);

  tLine.DrawLine( xStringPos.at(0),1861, xStringPos.at(0), 936);
  tLine.DrawLine( xStringPos.at(1),1865, xStringPos.at(1), 936);

  for( UInt_t j=0; j < xStringPos.size(); ++j){
    for( int i=0; i < 10; ++i){
      td.DrawMarker( xStringPos.at(j), yBelowOffset - detHeight*0.3 - (detHeight/100)*i);
    }
    for( int i=0; i < 50; ++i){
      td.DrawMarker( xStringPos.at(j), yBelowOffset - detHeight*0.65 + 7 - (detHeight/(1000./7.))*i);
    }
  }

 
  //******************************
  //******************************
  // Legend

  TPolyLine pline;
  TLine tline;

  vector<double> x,y;
  double yMidPoint;

  tlatex.SetTextSize( 0.051);
  tlatex.SetTextAngle( 90);
  tlatex.SetTextColor(kGray+2);
  tlatex.DrawLatex( 70, 900, "Side View");


  // Top DeepCore Section

  x.push_back( 940);
  x.push_back( 940);
  x.push_back( 722);
  x.push_back( 940);
  x.push_back( 940);

  yMidPoint = ((yBelowOffset - detHeight*0.28) + (yBelowOffset - detHeight*0.41))/2.;

  y.push_back( yBelowOffset - detHeight*0.28);
  y.push_back( yMidPoint + 5);
  y.push_back( yMidPoint);
  y.push_back( yMidPoint - 5);
  y.push_back( yBelowOffset - detHeight*0.41);

  pline.DrawPolyLine( x.size(), &x.at(0), &y.at(0));
  tline.DrawLine( 930, yBelowOffset - detHeight*0.28, 950, yBelowOffset - detHeight*0.28);
  tline.DrawLine( 930, yBelowOffset - detHeight*0.41, 950, yBelowOffset - detHeight*0.41);

  tlatex.SetTextSize(0.026);
  tlatex.SetTextAngle( 0);
  tlatex.SetTextColor( kBlack);

  tlatex.DrawLatex( 970, 910, "DeepCore strings have");
  tlatex.DrawLatex( 970, 870, "10 DOMs with a");
  tlatex.DrawLatex( 970, 830, "DOM-to-DOM spacing");
  tlatex.DrawLatex( 970, 790, "of 10 meters");
  
  // Bottom DeepCore Section

  y.clear();

  y.push_back( 360);
  y.push_back( 300 + 5);
  y.push_back( 300);
  y.push_back( 300 - 5);
  y.push_back( 240);

  pline.DrawPolyLine( x.size(), &x.at(0), &y.at(0));
  tline.DrawLine( x.at(0) - 10, y.at(0), x.at(0) + 10, y.at(0));
  tline.DrawLine( x.at(0) - 10, y.at(y.size()-1), x.at(0) + 10, y.at(y.size()-1));
  
  tlatex.DrawLatex( 970, 330, "50 HQE DOMs with a");
  tlatex.DrawLatex( 970, 290, "DOM-to-DOM spacing");
  tlatex.DrawLatex( 970, 250, "of 7 meters");

  x.clear();
  y.clear();

  x.push_back( 940);
  x.push_back( 940);
  x.push_back( 780);
  x.push_back( 940);
  x.push_back( 940);

  y.push_back( 190);
  y.push_back( 130 + 5);
  y.push_back( 130);
  y.push_back( 130 - 5);
  y.push_back( 70);

  tlatex.DrawLatex( 970, 160, "19 or 21 Normal DOMs");
  tlatex.DrawLatex( 970, 120, "with a DOM-to-DOM");
  tlatex.DrawLatex( 970, 80, "spacing of 17 meters");

  pline.DrawPolyLine( x.size(), &x.at(0), &y.at(0));
  tline.DrawLine( x.at(0) - 10, y.at(0), x.at(0) + 10, y.at(0));
  tline.DrawLine( x.at(0) - 10, y.at(y.size()-1), x.at(0) + 10, y.at(y.size()-1));

  // Add text for DOMs on strings 79 and 80, which may be unnecessary.

  if( false){
    x.clear();
    y.clear();
    
    x.push_back( 940);
    x.push_back( 940);
    x.push_back( 680);
    x.push_back( 940);
    x.push_back( 940);
    
    y.push_back( 490);
    y.push_back( 430 + 5);
    y.push_back( 430);
    y.push_back( 430 - 5);
    y.push_back( 370);
    
    tlatex.DrawLatex( 970, 460, "50 Admixed HQE and");
    tlatex.DrawLatex( 970, 420, "Normal DOMs with a");
    tlatex.DrawLatex( 970, 380, "spacing of 7 meters");

    pline.DrawPolyLine( x.size(), &x.at(0), &y.at(0));
    tline.DrawLine( x.at(0) - 10, y.at(0), x.at(0) + 10, y.at(0));
    tline.DrawLine( x.at(0) - 10, y.at(y.size()-1), x.at(0) + 10, y.at(y.size()-1));
  }


}
