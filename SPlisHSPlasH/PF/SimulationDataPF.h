#ifndef __SimulationDataPF_h__
#define __SimulationDataPF_h__

#include "SPlisHSPlasH/Common.h"
#include <vector>
#include "SPlisHSPlasH/FluidModel.h"

namespace SPH 
{	
	/** \brief Simulation data which is required by the method Projective Fluids introduced by Weiler, Koschier
	* and Bender \cite Weiler:2016.
	*/
	class SimulationDataPF
	{
	public:
		SimulationDataPF();
		virtual ~SimulationDataPF();

	protected:
		FluidModel *m_model;

		/** \brief particle position from last timestep */
		std::vector<Vector3r> m_old_position;

		/** \brief number of neighbors that are fluid particles */
		std::vector<unsigned int> m_num_fluid_neighbors;

	public:

		/** Initialize the arrays containing the particle data.
		*/
		virtual void init(FluidModel *model);

		/** Release the arrays containing the particle data.
		*/
		virtual void cleanup();

		/** Reset the particle data.
		*/
		virtual void reset();

		/** Important: First call m_model->performNeighborhoodSearchSort()
		 * to call the z_sort of the neighborhood search.
		 */
		void performNeighborhoodSearchSort();

		FORCE_INLINE const Vector3r getOldPosition(const unsigned int i) const
		{
			return m_old_position[i];
		}

		FORCE_INLINE Vector3r& getOldPosition(const unsigned int i)
		{
			return m_old_position[i];
		}

		FORCE_INLINE void setOldPosition(const unsigned int i, const Vector3r p)
		{
			m_old_position[i] = p;
		}

		FORCE_INLINE const unsigned int getNumFluidNeighbors(const unsigned int i) const
		{
			return m_num_fluid_neighbors[i];
		}

		FORCE_INLINE unsigned int& getNumFluidNeighbors(const unsigned int i)
		{
			return m_num_fluid_neighbors[i];
		}

		FORCE_INLINE void setNumFluidNeighbors(const unsigned int i, const unsigned int n)
		{
			m_num_fluid_neighbors[i] = n;
		}
	};
}

#endif