// nPDF viewer class
// Copyright (C) 2014  Legimet
//
// This file is part of nPDF.
// 
// nPDF is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// nPDF is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with nPDF.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _VIEWER_HPP_
#define _VIEWER_HPP_

extern "C" {
#include <mupdf/fitz.h>
}

class Viewer {
    private:
	fz_context *ctx;
	fz_document *doc;
	fz_page *page;
	fz_pixmap *pix;
	fz_device *dev;
	fz_rect bounds;
	float scale;
	int pageNo;
	int xPos;
	int yPos;
	bool curPageLoaded;
	bool fitWidth;
	int width;
	int height;
    public:
	static const int scroll;
	static const float zoom;
	static const unsigned char bgColor;
	Viewer();
	~Viewer();
	bool init();
	fz_context* getCtx() const;
	void openDoc(const char *path);
	void drawPage();
	void display();
	void next();
	void prev();
	void scrollUp();
	void scrollDown();
	void scrollLeft();
	void scrollRight();
	void setFitWidth();
	void unsetFitWidth();
	void zoomIn();
	void zoomOut();
};

#endif
