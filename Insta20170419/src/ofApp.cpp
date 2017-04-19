#include "ofApp.h"

ofApp::~ofApp() {

	for (ofxBulletBox* tmp : this->boxes) {
		delete tmp;
	}

	for (ofxBulletSphere* tmp : this->spheres) {
		delete tmp;
	}

	this->boxes.clear();
	this->spheres.clear();
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Bullet");
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(255);

	world.setup();
	world.enableGrabbing();
	//world.enableDebugDraw();
	world.setCamera(&camera);

	for (int i = 0; i < 128; i++) {
		ofxBulletBox* box = new ofxBulletBox();
		box->create(world.world, ofVec3f(ofRandom(-50, 50), ofRandom(64), ofRandom(-50, 50)), 0.0f, 10.0f, 1.0f, 10.0f);
		box->setProperties(0.75, 0.5);
		box->add();
		this->boxes.push_back(box);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetFrameNum() % 1 == 0) {
		ofxBulletSphere* sphere = new ofxBulletSphere();
		sphere->create(world.world, ofVec3f(ofRandom(1), -30.f, ofRandom(1)), 1.0f, ofRandom(0.5, 2.0));
		sphere->add();
		this->spheres.push_back(sphere);
	}

	world.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	glEnable(GL_DEPTH_TEST);

	camera.begin();

	ofSetLineWidth(1.f);
	ofSetColor(255, 0, 200);
	
	//world.drawDebug();

	for (int i = 0; i < this->spheres.size(); i++) {
		ofColor body_color;
		body_color.setHsb(i % 255, 255, 255);
		ofSetColor(body_color);
		this->spheres[i]->draw();
	}

	ofSetColor(0);
	for (int i = 0; i < this->boxes.size(); i++) {
		this->boxes[i]->draw();
	}

	camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
