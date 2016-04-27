#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofBackground(0);
    
    // add random 5 points
    for (int i = 0; i < 5; i++) {
        triangulation.addPoint(ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight())));
    }
    triangulation.triangulate();
    
    // gui
    panel.setup();
    panel.add(showDelaunayBackground.set("showDelaunayBackground", true));
    panel.add(showDelaunayWireframe.set("showDelaunayWireframe", true));
    panel.add(showDelaunayVertices.set("showDelaunayVertices", true));
    panel.add(showDelaunayCenter.set("showDelaunayCenter", true));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw the background of triangles
    if (showDelaunayBackground) {
        ofSetColor(0, 0, 127);
        ofFill();
        triangulation.draw();
        ofSetColor(255);
    }

    // draw wire frame of triangles
    if (showDelaunayWireframe) {
        ofNoFill();
        ofSetColor(255);
        triangulation.draw();
        ofFill();
    }
    
    // draw vertices of triangles
    if (showDelaunayVertices) {
        ofFill();
        glPointSize(10.0);
        ofSetColor(255, 0, 0, 255);
        ofMesh mesh = triangulation.triangleMesh;
        mesh.setMode(OF_PRIMITIVE_POINTS);
        mesh.draw();
        glPointSize(1.0);
        ofSetColor(255);
    }

    // draw centers of the mesh
    if (showDelaunayCenter) {
        ofSetColor(0, 255, 0, 255);
        for (int i = 0; i < triangulation.getNumTriangles(); i++) {
            int index1 = triangulation.triangleMesh.getIndex(i*3);
            int index2 = triangulation.triangleMesh.getIndex(i*3+1);
            int index3 = triangulation.triangleMesh.getIndex(i*3+2);
            
            ofVec3f vertex1 = triangulation.triangleMesh.getVertex(index1);
            ofVec3f vertex2 = triangulation.triangleMesh.getVertex(index2);
            ofVec3f vertex3 = triangulation.triangleMesh.getVertex(index3);
            
            ofVec3f center = (vertex1+vertex2+vertex3)/3.0;
            
            ofDrawCircle(center, 5);
        }
        ofSetColor(255);
    }
    
    // gui
    panel.draw();
    
    // debug
    ofDrawBitmapString("'r' to reset", ofPoint(10,20));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r'){
        triangulation.reset();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    triangulation.addPoint(ofPoint(x,y));
    triangulation.triangulate();
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
