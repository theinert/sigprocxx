// Copyright (C) 2011 Oliver Schulz <oliver.schulz@tu-dortmund.de>

// This is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 2.1 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.


#include "VectorOps.h"

#include <iostream>



using namespace std;


namespace sigpx {

std::ostream& VectorOps::print(std::ostream &os, const std::vector<int8_t> &v) { return printT(os, v); }
std::ostream& VectorOps::print(std::ostream &os, const std::vector<uint8_t> &v) { return printT(os, v); }
std::ostream& VectorOps::print(std::ostream &os, const std::vector<int16_t> &v) { return printT(os, v); }
std::ostream& VectorOps::print(std::ostream &os, const std::vector<uint16_t> &v) { return printT(os, v); }
std::ostream& VectorOps::print(std::ostream &os, const std::vector<int32_t> &v) { return printT(os, v); }
std::ostream& VectorOps::print(std::ostream &os, const std::vector<uint32_t> &v) { return printT(os, v); }
std::ostream& VectorOps::print(std::ostream &os, const std::vector<float> &v) { return printT(os, v); }
std::ostream& VectorOps::print(std::ostream &os, const std::vector<double> &v) { return printT(os, v); }

void VectorOps::stuff(std::vector<char> &stuffed, std::vector<int32_t> &sizes, const std::vector<char> &v) { stuffT(stuffed, sizes, v); }
void VectorOps::stuff(std::vector<int16_t> &stuffed, std::vector<int32_t> &sizes, const std::vector<int16_t> &v) { stuffT(stuffed, sizes, v); }
void VectorOps::stuff(std::vector<int32_t> &stuffed, std::vector<int32_t> &sizes, const std::vector<int32_t> &v) { stuffT(stuffed, sizes, v); }

void VectorOps::unstuff(const std::vector<char> &stuffed, const std::vector<int32_t> &sizes, size_t i, std::vector<char> &v) { unstuffT(stuffed, sizes, i, v); }
void VectorOps::unstuff(const std::vector<int16_t> &stuffed, const std::vector<int32_t> &sizes, size_t i, std::vector<int16_t> &v) { unstuffT(stuffed, sizes, i, v); }
void VectorOps::unstuff(const std::vector<int32_t> &stuffed, const std::vector<int32_t> &sizes, size_t i, std::vector<int32_t> &v) { unstuffT(stuffed, sizes, i, v); }

TGraph* VectorOps::graph(const std::vector<int16_t> &x, const std::vector<int16_t> &y)
	{ vector<int32_t> x2; copy(x, x2); vector<int32_t> y2; copy(y, y2); return graphT(x2, y2); }
TGraph* VectorOps::graph(const std::vector<int32_t> &x, const std::vector<int32_t> &y) { return graphT(x, y); }
TGraph* VectorOps::graph(const std::vector<float> &x, const std::vector<float> &y) { return graphT(x, y); }
TGraph* VectorOps::graph(const std::vector<double> &x, const std::vector<double> &y) { return graphT(x, y); }

TGraph* VectorOps::graph(const std::vector<int16_t> &y)
	{ vector<int32_t> y2; copy(y, y2); return graphT(y2); }
TGraph* VectorOps::graph(const std::vector<int32_t> &y) { return graphT(y); }
TGraph* VectorOps::graph(const std::vector<float> &y) { return graphT(y); }
TGraph* VectorOps::graph(const std::vector<double> &y) { return graphT(y); }


TGraph* VectorOps::draw(const std::vector<int16_t> &x, const std::vector<int16_t> &y, Option_t* chopt, Color_t lineColor, const TString &name, const TString &title)
	{ TGraph *g = graph(x, y); g->SetLineColor(lineColor); if (name.Length() > 0) g->SetName(name); if (title.Length() > 0) g->SetTitle(title); g->Draw(chopt); return g; }
TGraph* VectorOps::draw(const std::vector<int32_t> &x, const std::vector<int32_t> &y, Option_t* chopt, Color_t lineColor, const TString &name, const TString &title)
	{ TGraph *g = graph(x, y); g->SetLineColor(lineColor); if (name.Length() > 0) g->SetName(name); if (title.Length() > 0) g->SetTitle(title); g->Draw(chopt); return g; }
TGraph* VectorOps::draw(const std::vector<float> &x, const std::vector<float> &y, Option_t* chopt, Color_t lineColor, const TString &name, const TString &title)
	{ TGraph *g = graph(x, y); g->SetLineColor(lineColor); if (name.Length() > 0) g->SetName(name); if (title.Length() > 0) g->SetTitle(title); g->Draw(chopt); return g; }
TGraph* VectorOps::draw(const std::vector<double> &x, const std::vector<double> &y, Option_t* chopt, Color_t lineColor, const TString &name, const TString &title)
	{ TGraph *g = graph(x, y); g->SetLineColor(lineColor); if (name.Length() > 0) g->SetName(name); if (title.Length() > 0) g->SetTitle(title); g->Draw(chopt); return g; }

TGraph* VectorOps::draw(const std::vector<int16_t> &y, Option_t* chopt, Color_t lineColor, const TString &name, const TString &title)
	{ TGraph *g = graph(y); g->SetLineColor(lineColor); if (name.Length() > 0) g->SetName(name); if (title.Length() > 0) g->SetTitle(title); g->Draw(chopt); return g; }
TGraph* VectorOps::draw(const std::vector<int32_t> &y, Option_t* chopt, Color_t lineColor, const TString &name, const TString &title)
	{ TGraph *g = graph(y); g->SetLineColor(lineColor); if (name.Length() > 0) g->SetName(name); if (title.Length() > 0) g->SetTitle(title); g->Draw(chopt); return g; }
TGraph* VectorOps::draw(const std::vector<float> &y, Option_t* chopt, Color_t lineColor, const TString &name, const TString &title)
	{ TGraph *g = graph(y); g->SetLineColor(lineColor); if (name.Length() > 0) g->SetName(name); if (title.Length() > 0) g->SetTitle(title); g->Draw(chopt); return g; }
TGraph* VectorOps::draw(const std::vector<double> &y, Option_t* chopt, Color_t lineColor, const TString &name, const TString &title)
	{ TGraph *g = graph(y); g->SetLineColor(lineColor); if (name.Length() > 0) g->SetName(name); if (title.Length() > 0) g->SetTitle(title); g->Draw(chopt); return g; }


} // namespace sigpx
