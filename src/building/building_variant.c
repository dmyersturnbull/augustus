#include "building_variant.h"

#include "building/properties.h"
#include "building/rotation.h"
#include "city/view.h"
#include "core/image.h"

#define BUILDINGS_WITH_VARIANTS 5
#define CITY_DIRECTION_ANY -1
#define MAX_VARIANTS_PER_BUILDING 10

struct building_variant {
	const unsigned char number_of_variants;
	building_type type;
	int variants_offsets[MAX_VARIANTS_PER_BUILDING];
	int orientation;
};


static struct building_variant variants[BUILDINGS_WITH_VARIANTS] = {
	{5, BUILDING_PAVILION_BLUE, {0,1,2,3,4}, CITY_DIRECTION_ANY},
	{5, BUILDING_DECORATIVE_COLUMN, {0,2,4,6,8}, 0},
	{5, BUILDING_DECORATIVE_COLUMN, {1,3,5,7,9}, 1},
	{5, BUILDING_DECORATIVE_COLUMN, {0,2,4,6,8}, 2},
	{5, BUILDING_DECORATIVE_COLUMN, {1,3,5,7,9}, 3},
};

int building_variant_has_variants(building_type type)
{
	switch (type) {
	case BUILDING_PAVILION_BLUE:
	case BUILDING_DECORATIVE_COLUMN:
		return 1;
	default:
		return 0;
		break;
	}
}

int building_variant_get_image_id(building_type type)
{
	int variant_number = building_variant_get_number_of_variants(type);
	int rotation = building_rotation_get_rotation_with_limit(variant_number);
	return building_variant_get_image_id_with_rotation(type, rotation);
}

static struct building_variant *get_variant_data(building_type type)
{
	if (!building_variant_has_variants(type)) {
		return 0;
	}

	struct building_variant *variant = 0;
	for (int i = 0; i < BUILDINGS_WITH_VARIANTS; i++) {
		if ((city_view_orientation() / 2 != variants[i].orientation && variants[i].orientation != CITY_DIRECTION_ANY)) {
			continue;
		}

		if (variants[i].type == type) {
			variant = &variants[i];
			break;
		}
	}
	return variant;
}

int building_variant_get_image_id_with_rotation(building_type type, int rotation)
{
	struct building_variant *variant = get_variant_data(type);

	if (!variant) {
		return 0;
	}
	rotation = rotation % variant->number_of_variants;
	int group_id = building_properties_for_type(type)->image_group;
	int image_offset = building_properties_for_type(type)->image_offset + variant->variants_offsets[rotation];
	int image_id = group_id + image_offset;

	return image_id;
}

int building_variant_get_number_of_variants(building_type type)
{
	struct building_variant *variant = get_variant_data(type);

	if (!variant) {
		return 0;
	}
	return variant->number_of_variants;
}