#ifndef CONTRAFLOW_H
#define CONTRAFLOW_H


#include "segment.h"
#include "piping.h"
#include "interface.h"
#include <vector>

#include "stru3_matrix.h"



class Contraflow
{
public:
	Contraflow(int type, std::vector<SegmentData> segmentData_vec,
			PipingData pipingData, FluidData fluidData);
	void calculate(double _Q, double _T_in_0, stru3::DVec _T_s);
	Result get_result() { return result; }
private:
	void set_functions();
	stru3::DMat assemble_matrix();
	stru3::DVec assemble_RHS();

	double L_tot;	// total length
	int N_seg;
	int N_tot; // number of total nodes
	Piping piping;

	std::vector<Segment> segment_vec;

	double T_in_0;
	stru3::DVec T_s;
	Result result;
};

#endif