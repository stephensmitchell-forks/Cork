// +-------------------------------------------------------------------------
// | IntersectionProblem.h
// | 
// | Author: Gilbert Bernstein
// +-------------------------------------------------------------------------
// | COPYRIGHT:
// |    Copyright Gilbert Bernstein 2013
// |    See the included COPYRIGHT file for further details.
// |    
// |    This file is part of the Cork library.
// |
// |    Cork is free software: you can redistribute it and/or modify
// |    it under the terms of the GNU Lesser General Public License as
// |    published by the Free Software Foundation, either version 3 of
// |    the License, or (at your option) any later version.
// |
// |    Cork is distributed in the hope that it will be useful,
// |    but WITHOUT ANY WARRANTY; without even the implied warranty of
// |    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// |    GNU Lesser General Public License for more details.
// |
// |    You should have received a copy 
// |    of the GNU Lesser General Public License
// |    along with Cork.  If not, see <http://www.gnu.org/licenses/>.
// +-------------------------------------------------------------------------

#pragma once




namespace Cork
{
	namespace Intersection
	{
		enum class AdjustPerturbationResultCodes { SUCCESS = 0, MAXIMUM_PERTURBATION_REACHED };

		typedef SEFUtility::ResultWithReturnValue<AdjustPerturbationResultCodes, int>		AdjustPerturbationResult;


		class SelfIntersectionStats
		{
		public :

			SelfIntersectionStats( long		numSelfIntersections )
				: m_numSelfIntersections( numSelfIntersections )
			{}


			long		numSelfIntersections() const
			{
				return( m_numSelfIntersections );
			}

		private :

			long		m_numSelfIntersections;
		};



		class IntersectionProblemIfx
		{
		public:

			enum class IntersectionProblemResultCodes { SUCCESS = 0, OUT_OF_MEMORY, SUBDIVIDE_FAILED, EXHAUSTED_PURTURBATION_RETRIES, SELF_INTERSECTING_MESH, CONSOLIDATE_FAILED };

			typedef SEFUtility::Result<IntersectionProblemResultCodes>		IntersectionProblemResult;




			static std::unique_ptr<IntersectionProblemIfx>		GetProblem( MeshBase&							owner,
																			const Quantization::Quantizer&		quantizer,
																			const Cork::Math::BBox3D&			intersectionBBox );

			virtual ~IntersectionProblemIfx()
			{}

			virtual IntersectionProblemResult			FindIntersections() = 0;
			virtual IntersectionProblemResult			ResolveAllIntersections() = 0;

			virtual SelfIntersectionStats				CheckSelfIntersection() = 0;

			virtual void								commit() = 0;
		};

	}
}



