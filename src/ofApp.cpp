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
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw the background of triangles
    ofSetColor(0, 0, 127);
    ofFill();
    triangulation.draw();

    // draw wire frame of triangles
    ofNoFill();
    ofSetColor(255);
    triangulation.draw();
    
    // draw vertices of triangles
    ofFill();
    glPointSize(10.0);
    ofSetColor(255, 0, 0, 255);
    ofMesh mesh = triangulation.triangleMesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.draw();
    glPointSize(1.0);

    // draw centers of the mesh
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
