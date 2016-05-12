/*
 * Copyright (c) The Shogun Machine Learning Toolbox
 * Written (w) 2016 Heiko Strathmann
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the Shogun Development Team.
 */

#include <shogun/lib/config.h>
#include <shogun/lib/SGMatrix.h>
#include <shogun/lib/SGVector.h>
#include <shogun/features/DenseFeatures.h>
#include <shogun/distributions/kernel_exp_family/KernelExpFamilyNystrom.h>
#include <shogun/distributions/kernel_exp_family/impl/KernelExpFamilyNystromImpl.h>

using namespace shogun;

CKernelExpFamilyNystrom::CKernelExpFamilyNystrom() : CKernelExpFamily()
{
	m_impl=NULL;
}

CKernelExpFamilyNystrom::CKernelExpFamilyNystrom(CDenseFeatures<float64_t>* data,
			float64_t sigma, float64_t lambda, SGVector<index_t> inds)
			: CKernelExpFamily()
{
	SGMatrix<float64_t> mat=data->get_feature_matrix();
	m_impl = new KernelExpFamilyNystromImpl(mat, sigma, lambda, inds);
}

CKernelExpFamilyNystrom::CKernelExpFamilyNystrom(CDenseFeatures<float64_t>* data,
			float64_t sigma, float64_t lambda, index_t num_rkhs_basis) : CKernelExpFamily()
{
	SGMatrix<float64_t> mat=data->get_feature_matrix();
	m_impl = new KernelExpFamilyNystromImpl(mat, sigma, lambda, num_rkhs_basis);
}

CKernelExpFamilyNystrom::~CKernelExpFamilyNystrom()
{
	delete m_impl;
	m_impl=NULL;
}

