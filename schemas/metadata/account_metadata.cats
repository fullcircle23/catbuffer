import "transaction.cats"

# binary layout for an account metadata transaction
struct AccountMetadataTransactionBody
	# metadata target public key
	targetPublicKey = Key

	# metadata key scoped to source, target and type
	scopedMetadataKey = uint64

	# change in value size in bytes
	valueSizeDelta = int16

	# value size in bytes
	valueSize = uint16

	# difference between existing value and new value
	# \note when there is no existing value, new value is same this value
	# \note when there is an existing value, new value is calculated as xor(previous-value, value)
	value = array(byte, valueSize)

# binary layout for a non-embedded account metadata transaction
struct AccountMetadataTransaction
	const uint8 version = 1
	const EntityType entityType = 0x4144

	inline Transaction
	inline AccountMetadataTransactionBody

# binary layout for an embedded account metadata transaction
struct EmbeddedAccountMetadataTransaction
	inline EmbeddedTransaction
	inline AccountMetadataTransactionBody
