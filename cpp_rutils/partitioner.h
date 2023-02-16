#pragma once

#include <vector>

struct Partitioner
{
	Partitioner(size_t total_size, size_t chunk_size, size_t max_nb_cores = 0);
	Partitioner(const std::vector<size_t>& sizes);

	struct chunk_type
	{
		size_t _start;
		size_t _end;
	};

	//size_t _nb_parts;
	//size_t _part_size;

	std::vector<chunk_type> _chunks;
};

inline Partitioner::Partitioner(size_t total_size, size_t chunk_size, size_t max_nb_cores)
{
	size_t nb_cores = max_nb_cores ? max_nb_cores : std::thread::hardware_concurrency();
	size_t nb_parts = total_size / chunk_size + (unsigned)((total_size % chunk_size) > 0);
	if (nb_parts > nb_cores) {
		chunk_size = total_size / nb_cores;
		nb_parts = nb_cores;
	}
	_chunks.reserve(nb_parts);
	size_t start = 0, end = 0;
	for (; end < total_size; )
	{
		end = std::min(start + chunk_size, total_size);
		_chunks.push_back({ start, end });
		start = end;
	}
}

inline Partitioner::Partitioner(const std::vector<size_t>& sizes)
{
	size_t nb_parts = sizes.size();
	_chunks.reserve(nb_parts);
	size_t s = 0;
	for (size_t i = 0; i < nb_parts; i++)
	{
		size_t e = s + sizes[i];
		_chunks.emplace_back(s, e);
		s = e;
	}
}
